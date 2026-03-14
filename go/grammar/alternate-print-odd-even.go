package main

import (
	"fmt"
	"sync"
)

func solution1() {
	//channel 令牌传递 ping-pong模式，通过通信共享内存
	//注意结束条件，如何关闭两个goroutine，关闭channel的时机

	oddCh := make(chan struct{})
	evenCh := make(chan struct{})

	var wg sync.WaitGroup
	wg.Add(2)
	go func() {
		defer wg.Done()
		for i := 1; i <= 99; i += 2 {
			<-oddCh
			fmt.Println(i)
			evenCh <- struct{}{}
		}
	}()

	go func() {
		defer wg.Done()
		for i := 2; i <= 100; i += 2 {
			<-evenCh
			fmt.Println(i)
			if i < 100 { // 注意关闭条件,避免死锁
				oddCh <- struct{}{}
			}
		}
	}()

	//启动
	oddCh <- struct{}{}
	wg.Wait()
}

func solution2() {
	//共享变量+条件变量/锁 传统并发模型，扩展性好
	//但是比较复杂点

	var mu sync.Mutex
	cond := sync.NewCond(&mu)
	var wg sync.WaitGroup

	num := 1
	wg.Add(2)

	go func() {
		defer wg.Done()
		for {
			mu.Lock()
			for num <= 100 && num%2 == 0 {
				cond.Wait()
			}
			if num > 100 {
				cond.Broadcast()
				mu.Unlock()
				return
			}
			fmt.Println(num)
			num++
			cond.Broadcast()
			mu.Unlock()
		}
	}()

	go func() {
		defer wg.Done()
		for {
			mu.Lock()
			for num <= 100 && num%2 == 1 {
				cond.Wait()
			}
			if num > 100 {
				cond.Broadcast()
				mu.Unlock()
				return
			}
			fmt.Println(num)
			num++
			cond.Broadcast()
			mu.Unlock()
		}
	}()

	wg.Wait()
}

func main() {
	solution2()
}
