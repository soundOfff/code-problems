package main

import (
	"slices"
)

// Leetcode daily problem, 455 Assign Cookies
func FindContentChildren(g []int, s []int) int {
	content := 0
	slices.Sort(g)
	slices.Sort(s)

	for i := 0; i < len(s); i++ {
		ni := BinarySearch(s[i], g)
		if ni == -1 {
			continue
		} else {
			content++
			g = append(g[:ni], g[ni+1:]...)
		}
	}
	return content
}

func BinarySearch(s int, g []int) int {
	low := 0
	high := len(g) - 1
	for low <= high {
		median := (low + high) / 2
		if g[median] <= s {
			return median
		} else if g[median] < s {
			low = median + 1
		} else {
			high = median - 1
		}
	}
	if low == len(g) || g[low] > s {
		return -1
	}
	return -1
}
