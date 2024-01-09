package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func RangeSumBST(root *TreeNode, low int, high int) int {
	return dfs(root, low, high, 0)
}

func dfs(root *TreeNode, low, high int, acum int) int {
	if root == nil {
		return acum
	}
	if root.Val >= low && root.Val <= high {
		acum += root.Val
	}
	acum = dfs(root.Left, low, high, acum)
	acum = dfs(root.Right, low, high, acum)

	return acum
}