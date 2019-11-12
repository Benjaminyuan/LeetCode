class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        #先排序
        cur = nums[0]+ nums[1]+ nums[len(nums)-1]
        for i in range(0,len(nums)-2):
            if i> 0 and nums[i]==nums[i-1]:
                continue
            l = i+1
            r = len(nums)-1
            while l < r:
                val = nums[i]+nums[l]+nums[r]
                if abs(val- target)< abs(cur - target):
                    cur = val
                if val == target:
                    return target
                elif val< target:# 目标应该在右侧
                    l+=1
                else:# 目标应该在左侧
                    r-=1
        return cur