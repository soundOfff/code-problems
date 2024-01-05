package main

import "fmt"

// for testing the problems
func main() {
	beams := NumberOfBeams([]string{"011001", "000000", "010100", "001000"})
	fmt.Println(beams)
	content := FindContentChildren([]int{10, 9, 8, 7}, []int{10, 9, 8, 7})
	fmt.Println(content)
	matrix := LengthOfLIS2([]int{10, 9, 2, 5, 3, 7, 101, 18, 19, 1})
	fmt.Println(matrix)
}
