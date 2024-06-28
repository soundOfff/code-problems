package main

import (
	"fmt"
	"slices"
)

// Daily Leetcode problem 238.

func ProductExceptSelf(nums []int) []int {
	fmt.Println(nums)
	answer := make([]int, len(nums))
	for i := range nums {
		a_i := remove(nums, i)
		fmt.Println(a_i)
		fmt.Println(nums)
		answer[i] = getArrayProduct(a_i)
	}

	return answer
}

func getArrayProduct(nums []int) int {
	product := 1
	_, found := slices.BinarySearch(nums, 0)

	if found {
		return 0
	}

	for _, num := range nums {
		product *= num
	}
	return product
}

func remove(slice []int, s int) []int {
	return append(slice[:s], slice[s+1:]...)
}
