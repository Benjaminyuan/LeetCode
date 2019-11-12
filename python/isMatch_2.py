class Solution():
    
    def __init__(self):
        self.mem = {}
    #该算法取自Leetcode上的优秀算法
    '''
    个人理解：该字符串匹配实际上只有几种情况分类讨论即可
    因为模式匹配的过程很重复，面对重复问题用循环和递归会比较有效，循环的话就不说了，自己踩的坑现在还没有填完。。。。
    说递归：
    情况1：当前p[1]是*的，那么有两种情况,此时len(p)肯定要大于1：
        situation1：p[0]和s[0]是不匹配的，所以可以直接比较s和p[2](调用递归)
        situation2：p[0]和s[0]是相配的(p[0]==s[0] or p[0]='.'即通配符)，那比较s[1:]和p
    情况2：正常字符匹配(p[1]!='*')    
        判断s[0]==p[0]后直接调用递归比较s[1:]和p[1:]否则直接结束，
    细节:1：p为空的情况
         2：s为空，递归调用对原始的s,p都进行了切片操作
    优化:为了避免重复调用递归可以设置一个字典：存储已经判断过的s,p匹配

    '''
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if (s, p) in self.mem:
            return self.mem[(s, p)]
        if not p:
            return s == ''
        res = False
        if len(p) > 1 and p[1] == '*':
            res = self.isMatch(s, p[2:]) or (s != '' and (s[0] == p[0] or p[0] == '.') and self.isMatch(s[1:], p))
        else:
            res = s != '' and (p[0] == '.' or s[0] == p[0]) and self.isMatch(s[1:], p[1:])
        self.mem[(s, p)] = res
        return res