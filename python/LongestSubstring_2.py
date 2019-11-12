class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        a = []
        s_list = list(s)
        max_length = 1
        if s: #先决解大多数的情况
            for i in range(len(s_list)):
                if s_list[i] not in  a:
                        a.append(s_list[i])
                else:
                    j = a.index(s_list[i])+1
                    # 相比之下，步子跳大一点最好，前面一个算法步子太小，很浪费时间
                    del a[0:j]
                    a.append(s_list[i])
                max_length = max(max_length , len(a))
            return max_length
        else:#字符串为空的情况为少数，最好最后判断
            return 0