class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        # timeout step is too small 
        slen = len(s)
        wordsLen = len(words)
        possLoc = []
        if slen and wordsLen:
            # except border condition 
            wordLen = len(words[0])
            posiStart = 0
            wordsTemp = words[:]
            flag = True
            for j in range(wordLen):
                wordsTemp = words[:]
                flag = True
                i = j
                while i < slen:
                    temp = s[i:i+wordLen]
                    if temp in wordsTemp:
                        wordsTemp.remove(temp)
                        if flag:
                            # match first word and mark it 
                            posiStart = i 
                            flag = False
                        if wordsTemp ==[]:  
                            # finished a match and add the first index to return list
                            possLoc.append(posiStart)
                            i = posiStart+wordLen
                            wordsTemp = words[:]
                            flag = True
                        else:
                            i+=wordLen
                    elif  not  len(wordsTemp) == wordsLen :
                    # failed match in the match  proccess 
                        wordsTemp = words[:]
                        flag=True
                        i = posiStart+wordLen
                    else:
                        i+=wordLen
            return possLoc
        else:
            return []
if __name__=="__main__":
    Solu = Solution()
    s= "lingmindraboofooowingdingbarrwingmonkeypoundcake"
    words = ["fooo","barr","wing","ding","wing"]
    # s = "aaaaaaaa"
    # words = ["aa","aa","aa"]
    # s= "barfoothefoobarman"
    # words=["foo","bar"]
    print(Solu.findSubstring(s,words))