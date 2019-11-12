class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if abs(x)<= pow(2,31)-1 or x == -pow(2,31):
            token = '-'
            if abs(x)==x:
                token = '+'
            intList = list(str(abs(x)))
            intList.reverse()
            for item in intList:
                if int(item)==0:
                    intList=intList[intList.index(item)+1:]
                else:
                    break
            if intList:
                result = int(token+''.join(intList))
                if abs(result)<= pow(2,31)-1 or result == -pow(2,31):
                    return result
            return 0