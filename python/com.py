class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
				
        # d is the dictionary recording how many copies of each number there is in the list nums
        d = dict()
        for num in nums:
            if not num in d:
                d[num] = 0
            d[num] += 1
        
        pos_list = [i for i in d if i > 0]
        neg_list = [i for i in d if i < 0]
        
        # if either there is no positive number or negative number, then the only possibility is 0 + 0 + 0 = 0
        if pos_list == [] or neg_list == []:
            return [[0, 0, 0]] if 0 in d and d[0] > 2  else []

        # go through all positive numbers
        for i, x in enumerate(pos_list):
            
            # if there is more than one copy of x, then we can test case 1(a)
            if d[x] > 1 and -2 * x in d:
                    result.append([x, x, -2 * x])
			
            # now go through the rest of the positive numbers, test case 1(b)
            for y in pos_list[i + 1: len(pos_list)]:
                if -(x + y) in d:
                    result.append([x, y , -x - y])
        
        # do similar things to neg_list
        for i, x in enumerate(neg_list):
            
            # test case 2(a)
            if d[x] > 1 and -2 * x in d:
                    result.append([x, x, -2 * x])
                    
            # test case 2(b)
            for y in neg_list[i + 1: len(neg_list)]:
                if -(x + y) in d:
                    result.append([x, y , -x - y])
        
        # if we have at least one 0 in nums
        if 0 in d:
            # we can check case 3
            for i in pos_list:
                if -i in d:
                    result.append([-i, 0, i])
            # if we have more than three 0's, we can check case 4
            if d[0] >= 3:
                result.append([0, 0, 0])
            
        return result