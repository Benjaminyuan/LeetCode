class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        #思路：分割整体，一步步精确索引字符的位置
        if numRows < len(s):
            container = []
            strList = list(s)
            space = numRows*2-2
            baseIndex = numRows-2
            temp = []
            if space:
                for i in range(numRows):
                    temp.append(strList[i])
                    container.append(temp)
                    temp = []
                for j in range(numRows,len(strList)):
                    judge = (j-numRows)%space
                    index = abs(judge-baseIndex)
                    temp =container[index]
                    temp.append(strList[j])
                out = ''
                for k in range(numRows):
                    out+= str(''.join(container[k]))
            else:
                out = s
         
        else:
            out =s 
        return out 
