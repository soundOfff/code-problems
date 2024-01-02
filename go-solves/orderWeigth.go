package main

import (
	"strconv"
	"strings"
)

func OrderWeight(str string) string {
	arr := sumOfDigitsArray(str)
	a := strings.Fields(str)
	result := ""

	for i, el := range arr {
		if i == len(arr)-1 {
			for val := range el {
				result += a[val]
			}
		} else {
			for val := range el {
				result += a[val] + " "
			}
		}
	}

	return result
}

func sumOfDigitsArray(input string) []map[int]int {
	numbersStr := strings.Fields(input)
	result := make([]map[int]int, len(numbersStr))

	for i, numStr := range numbersStr {
		field := map[int]int{
			i: 0,
		}
		for _, digitChar := range numStr {
			digit, _ := strconv.Atoi(string(digitChar))
			field[i] += digit
		}
		result[i] = field
	}

	selectionSort(result, numbersStr)

	return result
}

func selectionSort(arr []map[int]int, origin []string) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIndex := i
		for j := i + 1; j < n; j++ {
			k1, j1 := getValue(arr[j])
			k2, j2 := getValue(arr[minIndex])
			if k1 < k2 {
				minIndex = j
			} else if k1 == k2 {
				a := origin[j1]
				b := origin[j2]
				if a <= b {
					minIndex = j
				}
			}
		}
		if minIndex != i {
			arr[i], arr[minIndex] = arr[minIndex], arr[i]
		}
	}
}

func getValue(m map[int]int) (int, int) {
	for o, v := range m {
		return v, o
	}
	return 0, 0
}
