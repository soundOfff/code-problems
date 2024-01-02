package main

func RainVolume(towers []int) int {
	acum := 0
	lm := towers[0]
	rm := findMax(towers[2:])

	for i := 1; i < len(towers)-1; i++ {
		min := getMin(lm, rm)
		if min > towers[i] {
			acum += min - towers[i]
		}
		if lm < towers[i] {
			lm = towers[i]
		}
		if rm <= towers[i] {
			rm = findMax(towers[i+1:])
		}
	}
	return acum
}

func findMax(arr []int) int {
	if len(arr) == 0 {
		return 0
	}
	max := arr[0]
	for i := 1; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
		}
	}
	return max
}

func getMin(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
