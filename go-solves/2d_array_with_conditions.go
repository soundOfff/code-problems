package main

import (
	"slices"
)

func FindMatrix(nums []int) [][]int {
	hash := map[int][]int{}
	matrix := [][]int{}
	row := 0
	for _, num := range nums {
		if !isInRow(hash[row], num) {
			hash[row] = append(hash[row], num)
		} else {
			row++
			hash[row] = append(hash[row], num)
		}
	}
	for _, row := range hash {
		matrix = append(matrix, row)
	}
	return matrix
}

func isInRow(row []int, num int) bool {
	return slices.Contains(row, num)
}
