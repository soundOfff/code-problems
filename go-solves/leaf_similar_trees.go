package main

import (
	"reflect"
)

func LeafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	l1 := []int{}
	l2 := []int{}
	traverseDfs(root1, &l1)
	traverseDfs(root2, &l2)
	if len(l1) != len(l2) {
		return false
	}
	return reflect.DeepEqual(l1, l2)
}

func traverseDfs(root *TreeNode, leafs *[]int) {
	if root == nil {
		return
	}
	if root.Left == nil && root.Right == nil {
		*leafs = append(*leafs, root.Val)
	}
	traverseDfs(root.Left, leafs)
	traverseDfs(root.Right, leafs)
}
