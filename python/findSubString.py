class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        slen = len(s)
        wordsLen = len(words)
        possLoc = []
        if slen and wordsLen:
            possiList=set()
            wordLen = len(words[0])
            posiStart = 0
            possiList = []
            i = 0
            wordsTemp = words
            while i < slen:
                if s[i:i+wordLen] in words and s[i:i+wordLen] not in possiList :
                    possiList.append(s[i:i+wordLen])
                    posiStart = i 
                    if len(possiList) == wordsLen:  
                        possLoc.append(posiStart-wordLen*(wordsLen-1))
                        i = posiStart-wordLen*wordsLen+2*wordLen
                    else:
                         i+=wordLen
                elif s[i:i+wordLen] not in words:
                         i+=wordLen
                         possiList=[]
                else:
                    possiList=[]
            return possLoc
        else:
            return 
if __name__=="__main__":
    Solu = Solution()
    s = "barfoofoobarthefoobarman"
    words=["bar","foo","the"]
    # s= "barfoothefoobarman"
    # words=["foo","bar"]
    print(Solu.findSubstring(s,words))