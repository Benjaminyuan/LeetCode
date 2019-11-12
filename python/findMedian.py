class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        #人生苦短，我用python，如果换作其他的语言想必更底层的代码又要折腾一翻
        a = nums1+nums2
        a.sort()
        if  not(len(a)%2):
            return 0.5*(a[int(len(a)/2)]+a[int(len(a)/2)-1])
        else :
            return a[int(len(a)/2)]