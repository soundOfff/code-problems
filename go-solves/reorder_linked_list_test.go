package main

import (
	"slices"
	"testing"
)

// TestProductExceptSelf calls ProductExceptSelf with a array, checking
// for a valid return value.
func TestReorderLinkedList(t *testing.T) {
	input := []ListNode{{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: nil}}}}}
	expectedValue := []int{1, 2, 3, 4}
	ReorderLinkedList(&input[0])

	if int := slices.Compare(output, expectedValue); int != 0 {
		t.Fatalf(`ProductExceptSelf(%v) = %v, want %v`, input, output, expectedValue)
	}
}
