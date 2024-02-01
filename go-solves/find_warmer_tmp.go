package main

import "fmt"

func DailyTemperatures(temperatures []int) []int {
	result := make([]int, len(temperatures))
	stack := make([]int, 0)
	for i, temp := range temperatures {
		fmt.Println(temp, stack)
		for len(stack) > 0 && temp > temperatures[stack[len(stack)-1]] {
			idx := stack[len(stack)-1]
			stack = stack[:len(stack)-1] // pop
			result[idx] = i - idx        // update
		}
		stack = append(stack, i)
	}

	return result
}
