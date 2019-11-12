class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #暴力枚举
        minInt = (1 << 32) -1
        print(minInt)
        for i in range(0,len(nums)):
            if i <= (len(nums)-3):
                for j in range(i+1,len(nums)):
                    for k in range(j+1,len(nums)):
                        sumInt = nums[i]+nums[j]+nums[k]
                        print(sumInt)
                        if abs(sumInt-target)< minInt:
                            rInt = sumInt
                            minInt = abs(sumInt-target)
        return rInt  