class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i=0
        j=len(height)-1
        area = 0
        while(i<j):
            if(height[i]<height[j]):
                area = max(area,height[i]*(j-1))
                i+=1      
            else:
                area = max(area,height[j]*(j-i))
                j-=1
        return area