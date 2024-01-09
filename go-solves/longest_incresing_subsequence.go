package main

// 300. Longest Increasing Subsequence
func LengthOfLIS3(nums []int) int {
	max := 0
	for i := 0; i < len(nums)-1; i++ {
		aux := 0
		for j := 1; j < len(nums); j++ {
			if nums[i] < nums[j] {
				aux++
			}
			if aux > max {
				max = aux
			}
		}
	}
	return max
}
