package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func ReorderLinkedList(head *ListNode) {
	arr := traverseList(head)
	fmt.Println(arr)
}

func traverseList(head *ListNode) []int {
	result := []int{}
	for head != nil {
		result = append(result, head.Val)
		head = head.Next
	}
	return result
}
