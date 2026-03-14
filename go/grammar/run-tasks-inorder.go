package main

import (
	"fmt"
	"sync"
)

func task1() {
	fmt.Println("task1 Done")
}

func task2() {
	fmt.Println("task2 Done")
}
func task3() {
	fmt.Println("task3 Done")
}

func runWithChannel() {
	ch1 := make(chan struct{})
	ch2 := make(chan struct{})
	var wg sync.WaitGroup
	wg.Add(3)

	go func() {
		defer wg.Done()
		task1()
		close(ch1)
	}()
	go func() {
		defer wg.Done()
		<-ch1
		task2()
		close(ch2)
	}()
	go func() {
		defer wg.Done()
		<-ch2
		task3()
	}()
	wg.Wait()
}

func runWithCond() {
	//互斥锁+条件变量 控制阶段 扩展性好，更灵活，但是更重
	var mu sync.Mutex
	cond := sync.NewCond(&mu)
	var wg sync.WaitGroup

	stage := 1
	wg.Add(3)

	go func() {
		defer wg.Done()
		mu.Lock()
		for stage != 1 {
			cond.Wait()
		}
		task1()
		stage = 2
		cond.Broadcast()
		mu.Unlock()
	}()
	go func() {
		defer wg.Done()
		mu.Lock()
		for stage != 2 {
			cond.Wait()
		}
		task2()
		stage = 3
		cond.Broadcast()
		mu.Unlock()
	}()
	go func() {
		defer wg.Done()
		mu.Lock()
		for stage != 3 {
			cond.Wait()
		}
		task3()
		mu.Unlock()
	}()
	wg.Wait()
}

func main() {
	runWithChannel()
	fmt.Println("-----------------------")
	runWithCond()
}
