class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        for i in range(len(nums)):
            temp = target-nums[i]
            if temp in nums and nums.index(temp)!=i:
                result.append(i)
                result.append(nums.index(temp))
                break
        return result
so = Solution()
result=so.twoSum([3,2,4],6)
print(result)