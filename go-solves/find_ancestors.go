package main

// 1026. Maximum Difference Between Node and Ancestor

func MaxAncestorDiff(root *TreeNode) int {
	// return max(traverse(root, root.Left.Left, -1), traverse(root, root.Right.Right, -1))
	return 0
}

// func traverse(root *TreeNode, child *TreeNode, max int) int {
// 	if root == nil || child == nil {
// 		return max
// 	}

// 	dl := int(math.Abs(float64(root.Left.Left.Val) - float64(root.Val)))
// 	dr := int(math.Abs(float64(root.Right.Right.Val) - float64(root.Val)))

// 	fmt.Println(root.Val)
// 	if dl > dr && dl > max {
// 		max = dl
// 	} else if dr > dl && dr > max {
// 		max = dr
// 	}

// 	max = traverse(root.Left, max)
// 	max = traverse(root.Right, max)

// 	return max
// }

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
