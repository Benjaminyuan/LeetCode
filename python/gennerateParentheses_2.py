class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # 用动态规划的思想去写
        charNum = 2*n
        rlist = []
        def putParent(left,right,item):
            if len(item)==charNum:
                if item  not in rlist:
                    rlist.append(item)
                return 0
            if left :
                if left >= right:
                    putParent(left-1,right,item+'(')
                else:
                    putParent(left,right-1,item+')')
                    putParent(left-1,right,item+'(')
            else:
                    putParent(0,right,item+')')
        putParent(n,n,'')
        return rlist
if __name__=="__main__":
    count = Solution()
    rlist = count.generateParenthesis(4)
    print(rlist)
    right = ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
    for item in rlist:
        right.remove(item)
    print(right)