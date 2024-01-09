package main

import "fmt"

// for testing the problems
func main() {
	beams := NumberOfBeams([]string{"011001", "000000", "010100", "001000"})
	fmt.Println(beams)
	content := FindContentChildren([]int{10, 9, 8, 7}, []int{10, 9, 8, 7})
	fmt.Println(content)
	operations := MinOperations([]int{2, 3, 3, 2, 2, 4, 2, 3, 4})
	fmt.Println(operations)
	sequences := LengthOfLIS([]int{10, 9, 2, 5, 3, 7, 101, 18})
	fmt.Println(sequences)
	sum := RangeSumBST(&TreeNode{Val: 10, Left: &TreeNode{Val: 5, Left: &TreeNode{Val: 3}, Right: &TreeNode{Val: 7}}, Right: &TreeNode{Val: 15, Right: &TreeNode{Val: 18}}}, 7, 15)
	fmt.Println(sum)
	matrix := LengthOfLIS2([]int{10, 9, 2, 5, 3, 7, 101, 18, 19, 1})
	fmt.Println(matrix)
}
