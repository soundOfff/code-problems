package main

import (
	"bufio"
	"fmt"
	"os"
)

func B() {
	var x, n, maxI, minI, result int
	var aux []int
	in := bufio.NewReader(os.Stdin)

	max := -99999
	min := 99999

	fmt.Scanf("%d", &x)
	for i := 0; i < x; i++ {
		fmt.Scanf("%d", &n)
		aux = ReadArrInt(in)
		arr := make([]int, n)
		for index, a := range aux {
			arr[index] = a
			if a > max {
				max = a
				maxI = index
			}
			if a < min {
				min = a
				minI = index
			}
		}
		if arr[minI] < 2 {
			arr[minI]++
		} else {
			arr[maxI]++
		}

		result = 1
		for _, el := range arr {
			result = result * el
		}
		fmt.Println(result)
	}
}
