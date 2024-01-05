package main

import (
	"fmt"
	"math"
	"slices"
)

// Leetcode daily problem 300 Longest Increasing Subsequence - worst time complexity

func LengthOfLIS(nums []int) int {
	dp := make([]int, len(nums))

	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				dp[i] = int(math.Max(float64(dp[i]), float64(dp[j]+1)))
			}
		}
	}
	return slices.Max(dp) + 1
}

// better approach with binary search

func LengthOfLIS2(nums []int) int {
	sub := make([]int, 0, len(nums)>>1)

	for _, num := range nums {
		fmt.Println("---------", num, "---------")
		index := binarySearch(sub, num)
		if index == len(sub) {
			sub = append(sub, num)
		} else {
			sub[index] = num
		}
		fmt.Println(sub, index)
	}

	return len(sub)
}

// Esta binaria calcula basandose en si no hay un numero mayor que el parametro num
// Entonces lo que hace es devolver un indice igual a la longitud y despues en el codigo
// De la funcion se hace un append para agregar el numero y aumentar la long.
// En el caso que el numero sea menor que el ultimo numero del slice, entonces se reemplaza.
func binarySearch(sub []int, num int) int {
	l, r := -1, len(sub)
	for r-l > 1 {
		m := (l + r) / 2
		if num > sub[m] {
			l = m
		} else {
			r = m
		}
	}
	return r
}
