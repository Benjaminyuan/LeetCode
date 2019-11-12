package main

import (
	"fmt"
)

func main() {
	nums := []int{1, 2, 3}
	res := permute(nums)
	fmt.Println(res)

}

/*
 * @lc app=leetcode id=46 lang=golang
 *
 * [46] Permutations
 */
func permute(nums []int) [][]int {
	var res [][]int
	if len(nums) == 0 {
		return res
	}
	temp := make([]int, 0, 3)
	res = dp(nums, 0, temp, res)
	return res
}
func swap(num []int, i int, j int) {
	temp := num[i]
	num[i] = num[j]
	num[j] = temp
}
func dp(nums []int, start int, temp []int, res [][]int) [][]int {
	if start == len(nums)-1 {
		temp = append(temp, nums[start])
		copyA := make([]int, len(nums))
		copy(copyA, temp)
		res = append(res, copyA)
		return res

	}
	for i := start; i < len(nums); i++ {
		if start != i && nums[start] == nums[i] {
			continue
		}
		swap(nums, start, i)
		temp = append(temp, nums[start])
		res = dp(nums, start+1, temp, res)
		swap(nums, start, i)
		temp = temp[:len(temp)-1]
	}
	return res
}
