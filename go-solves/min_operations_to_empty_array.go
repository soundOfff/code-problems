package main

import "math"

// 2870. Minimum Number of Operations to Make Array Empty

func MinOperations(nums []int) int {
	op := 0
	items := map[int]int{}

	for i := 0; i < len(nums); i++ {
		if _, ok := items[nums[i]]; !ok {
			items[nums[i]] = 1
		} else {
			items[nums[i]]++
		}
	}

	for _, v := range items {
		if v == 1 {
			return -1
		}
		op += int(math.Floor(float64(v / 3)))
		if v%3 != 0 {
			op += 1
		}
	}

	return op
}
