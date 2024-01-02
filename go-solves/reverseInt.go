package main

import "strconv"

func Reverse(x int) int {
	str := strconv.Itoa(x)
	var num string
	for _, v := range str {
		num += string(v)
	}
	res, _ := strconv.Atoi(num)
	return res
}
