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
	isLeafSimilar := LeafSimilar(
		&TreeNode{Val: 3, Left: &TreeNode{Val: 5, Left: &TreeNode{Val: 6}, Right: &TreeNode{Val: 2, Left: &TreeNode{Val: 7}, Right: &TreeNode{Val: 4}}}, Right: &TreeNode{Val: 1, Left: &TreeNode{Val: 9}, Right: &TreeNode{Val: 8}}},
		&TreeNode{Val: 3, Left: &TreeNode{Val: 5, Left: &TreeNode{Val: 6}, Right: &TreeNode{Val: 7}}, Right: &TreeNode{Val: 1, Left: &TreeNode{Val: 4}, Right: &TreeNode{Val: 2, Left: &TreeNode{Val: 9}, Right: &TreeNode{Val: 8}}}},
	)
	fmt.Println(isLeafSimilar)
	matrix := FindMatrix([]int{1, 3, 4, 1, 2, 3, 1})
	fmt.Println(matrix)
}
