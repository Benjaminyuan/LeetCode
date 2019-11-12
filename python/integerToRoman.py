class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        #加一点备忘录思想。。。
        items = {0:{},1:{1:'C',2:'D'},2:{1:'X',2:'L'},3:{1:'I',2:'V'}}
        result = {0:{1:'M',2:'MM',3:'MMM',0:''},1:{4:'CD',9:'CM',0:''},2:{4:'XL',9:'XC',0:''},3:{4:'IV',9:'IX',0:''}}
        finalres = ''
        for i in range(0,4):
            multi = pow(10,3-i)
            numStr = int(num/multi)
            num = num%multi
            if  numStr in result[i]:
                finalres+=result[i][numStr]
            else:
                repeat_1 = numStr%5
                repeat_2 = int(numStr/5)
                # print(i)
                # print(items[i])
                finalres+= repeat_2*items[i][2]+repeat_1*items[i][1]
        return finalres