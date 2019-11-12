class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #可以直接暴力求解，但是O(N^3)
        # 这个解法避免了多层循环：分清楚了条件循环
        rList = []
        d = dict()
        for item in nums:
            if not item in d:
                d[item]= 0
            d[item]+=1
        pos_list = [ i for i in d if i > 0 ]#这个数组中不能有重复的数字
        nag_list = [ i for i in d if i < 0 ]
        print(d)
        if pos_list == [] or nag_list ==[]:
            return [[0,0,0]] if 0 in  d and d[0]> 2 else []
        for i,x in enumerate(pos_list):
            if d[x]>1 and -2*x in d:
                rList.append([x,x,-2*x])
            for y in pos_list[i+1:len(pos_list)]:
                if -(x+y) in d :
                    rList.append([x,y,-x-y])
        for i,x in enumerate(nag_list):
            if d[x]>1 and -2*x in d:
                    rList.append([x,x,-2*x])
            for y in nag_list[i+1:len(nag_list)]:
                if -(x+y) in d:
                    rList.append([x,y,-x-y])
        if  0 in d:
            for i in pos_list:
                if -i in nag_list:
                    rList.append([i,-i,0])
            if d[0]>2:
                rList.append([0,0,0])
        return rList