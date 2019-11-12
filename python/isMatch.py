class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if s and p :
            string = list(s)
            a = list(p)
            pointIndex = [ x for x,v in enumerate(a) if v == '.']
            starIndex = [x for x, v in enumerate(a) if v == '*']
            matchingPos = 0
            i = 0
            print(pointIndex)
            print(starIndex)
            while matchingPos<len(a) and i<len(string):
                if string[i] == a[i] or matchingPos in pointIndex:
                    matchingPos+=1
                    i+=1
                elif matchingPos in starIndex:
                    temp = string[i]
                    while(i<len(a)-1 and string[i]==temp):
                        i+=1
                    matchingPos+=1
                    i+=1
                else:
                    return False
            if i==len(string) and matchingPos == len(a):
                return True
            else:
                return False
        else:
            return False

        