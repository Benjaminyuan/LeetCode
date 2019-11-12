class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s=list(s)
        a = s.reverse()
        for i in renge(len(s)):
            if a[i] == s[i]:
                for j in range(i,len(s)):
                    if a[j]==s[j]
                    