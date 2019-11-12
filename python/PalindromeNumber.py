class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x and x>0:
            if x > 10:
                strX = list(str(x))
                strXTemp = strX
                strX.reverse()
                if strX == strXTemp:
                    return True
                else:
                    return False
            else:
                return True
        else:
            return False
    