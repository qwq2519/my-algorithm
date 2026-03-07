package main

import "fmt"

func main() {
	arr1 := make([]int, 0, 4)
	arr1 = append(arr1, 1)
	arr2 := append(arr1, 2)
	fmt.Printf("arr1=%v len=%d cap=%d data=%p\n", arr1, len(arr1), cap(arr1), arr1)
	fmt.Printf("arr2=%v len=%d cap=%d data=%p\n", arr2, len(arr2), cap(arr2), arr2)
	arr3 := append(arr1, 3)
	fmt.Println()
	fmt.Printf("arr1=%v len=%d cap=%d data=%p\n", arr1, len(arr1), cap(arr1), arr1)
	fmt.Printf("arr2=%v len=%d cap=%d data=%p\n", arr2, len(arr2), cap(arr2), arr2)
	fmt.Printf("arr3=%v len=%d cap=%d data=%p\n", arr3, len(arr3), cap(arr3), arr3)
}
