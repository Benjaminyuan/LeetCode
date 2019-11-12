class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s :
            return s
        lastList=[]
        s = list(s)
        lastList.append(s[0])
        # 逐个遍历，找到重复元素对应的下标，然后以下标最大值开始截断数组
        # 然后翻转数组，比较即可（求回文字符串的套路。。。）
        for i in range(len(s)):
            indexs = [a for a,v in enumerate(s) if v==s[i]]        
            indexs = indexs[1:]
            while indexs:
                lastIndex = indexs.pop()
                cha = lastIndex-i+1
                if not(cha%2):
                    front =s[i:int(cha/2)+i]  
                    end  = s[int(cha/2)+i:lastIndex+1]
                else:
                    front = s[i:int(cha/2)+i]
                    end = s[int(cha/2)+1+i:lastIndex+1]
                front.reverse()
                if ''.join(front) == ''.join(end):
                    if len(lastList)< cha+1:
                        lastList = s[i:lastIndex+1]
                        break
                    else:
                        break
        return ''.join(lastList)

                    
                    