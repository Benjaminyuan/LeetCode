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
	var temp []int 
	res = dp(nums,0,temp,res)
	return res 
}
func swap(num []int,i int ,j int ){
	temp :=num[i]
	num[i] = num[j]
	num[j]= temp
}
func dp(nums []int, start int,temp []int,res [][]int) [][]int{
	if(start == len(nums)-1){
		temp = append(temp,nums[start])
		res = append(res,temp)
		return res

	}
	for i:=start;i<len(nums);i++{
		swap(nums,start,i)
		temp = append(temp,nums[i])
		res = dp(nums,i+1,temp,res)
		swap(nums,start,i)
		temp = make([]int,len(nums))
	}
	return res
}
