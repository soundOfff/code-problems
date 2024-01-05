package main

import (
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
