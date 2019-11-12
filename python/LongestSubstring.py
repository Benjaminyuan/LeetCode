class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        #该方法为简单遍历，运行超时
        a = []
        s_list = list(s)
        max_length = 1
        if not(s):
            return 0 
        for i in range(len(s_list)):
            a.append(s_list[i])
            for j in range(i+1,len(s_list)):
                if s_list[j] not in  a:
                    a.append(s_list[j])
                else :
                    break
            max_length = max(max_length , len(a))
            if max_length == len(s_list):
                return len(s_list)
            if max_length >= 97:
                return max_length
            a = []
        return max_length
