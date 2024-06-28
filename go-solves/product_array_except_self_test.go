package main

import (
	"slices"
	"testing"
)

// TestProductExceptSelf calls ProductExceptSelf with a array, checking
// for a valid return value.
func TestProductExceptSelf(t *testing.T) {
	input := []int{1, 2, 3, 4}
	expectedValue := []int{24, 12, 8, 6}
	output := ProductExceptSelf(input)

	if int := slices.Compare(output, expectedValue); int != 0 {
		t.Fatalf(`ProductExceptSelf(%v) = %v, want %v`, input, output, expectedValue)
	}
}
