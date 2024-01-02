package main

import "fmt"

func TargetGame(values []int) int {
	acum := 0
	loading := false
	for i := 0; i < len(values)-2; i += 2 {
		fmt.Println(loading)
		if loading {
			loading = false
		}
		if values[i] <= 0 {
			continue
		} else if !loading {
			if values[i] > values[i+1] {
				acum += values[i]
				loading = true
			} else {
				if values[i+1] < values[i+2] {
					continue
				} else {
					acum += values[i+1]
					loading = true
				}
			}
		}
	}

	return acum
}
