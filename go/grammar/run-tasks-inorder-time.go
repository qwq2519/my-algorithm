package main

import (
	"context"
	"errors"
	"fmt"
	"sync"
	"time"
)

func taskA(ctx context.Context) error {
	fmt.Println("taskA")
	select {
	case <-time.After(200 * time.Millisecond):
		return nil
	case <-ctx.Done():
		return ctx.Err()
	}
}

func taskB(ctx context.Context) error {
	fmt.Println("taskB")
	select {
	case <-time.After(200 * time.Millisecond):
		return errors.New("taskB failed")
	case <-ctx.Done():
		return ctx.Err()
	}
}
func taskC(ctx context.Context) error {
	fmt.Println("taskC")
	select {
	case <-time.After(200 * time.Millisecond):
		return nil
	case <-ctx.Done():
		return ctx.Err()
	}
}

func compensate(ctx context.Context) error {
	fmt.Println("compensate")
	select {
	case <-time.After(100 * time.Millisecond):
		return nil
	case <-ctx.Done():
		return ctx.Err()
	}
}

// 尝试发送err，非阻塞
func sendErr(errCh chan error, err error) {
	select {
	case errCh <- err:
	default:
	}
}

func run(ctx context.Context, cancel context.CancelFunc) error {
	ch1 := make(chan struct{})
	ch2 := make(chan struct{})
	errCh := make(chan error, 1)
	var wg sync.WaitGroup
	wg.Add(3)
	go func() {
		defer wg.Done()
		if err := taskA(ctx); err != nil {
			sendErr(errCh, fmt.Errorf("taskA: %w", err))
			cancel()
			return
		}
		close(ch1)
	}()
	go func() {
		defer wg.Done()
		select {
		case <-ch1: //阻塞等待，因为没default
		case <-ctx.Done():
			return
		}
		if err := taskB(ctx); err != nil {
			//单独给补偿任务开个定时器
			cctx, ccancel := context.WithTimeout(context.Background(), 200*time.Millisecond)
			defer ccancel()
			_ = compensate(cctx)
			sendErr(errCh, fmt.Errorf("taskB : %w", err))
			cancel()
			return
		}
		close(ch2)
	}()
	go func() {
		defer wg.Done()
		select {
		case <-ch2:
		case <-ctx.Done():
			return
		}
		if err := taskC(ctx); err != nil {
			sendErr(errCh, fmt.Errorf("taskC: %w", err))
			cancel()
			return
		}
	}()

	done := make(chan struct{})
	go func() {
		wg.Wait()
		close(done)
	}()

	select {
	case err := <-errCh:
		<-done
		return err
	case <-done:
		return nil
	case <-ctx.Done():
		<-done
		select {
		case err := <-errCh:
			return err
		default:
			return ctx.Err()
		}
	}
}

func main() {
	ctx, cancel := context.WithTimeout(context.Background(), time.Millisecond*100)
	defer cancel()
	if err := run(ctx, cancel); err != nil {
		fmt.Println("failed:", err)
		return
	}
	fmt.Println("success")
}
