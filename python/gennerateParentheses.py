class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        #这样会漏情况,if 后面的情况并不是基础情况
        def recorsiveFun(n):
            if n == 1:
                return ["()"] 
            else:
                rlist = []
                print("递归"+str(n))
                tempList = recorsiveFun(n-1)
                for i,item in enumerate(tempList):
                    if item+'()' not in rlist:
                        rlist.append(item+"()")
                    if '('+item+')' not in tempList:
                        rlist.append('('+item+')')
                    if "()"+item not in rlist:
                        rlist.append("()"+item)
            return rlist
        rlist = recorsiveFun(n)
        return rlist
if __name__=="__main__":
    count = Solution()
    rlist = count.generateParenthesis(4)
    print(rlist)
    right = ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
    for item in rlist:
        right.remove(item)
    print(right)