class MaxSubString():
    def __init__(self, *args, **kwargs):
        self.sub_left = 0
        self.sub_right = 0
        self.try_new = True
        self.sum = 0 
    def caculate(self,array):
        sum = 0 
        # 每次选取的子串第一个一定是正数，所以当sum小于0时，在当前的self.sub_left到该位置的区间是找不出更大子串的，这个算法有缺陷：数组中一定要又整数，
        # 泛化不够好
        for i in range(len(array)):
            if self.try_new == True:
                if array[i] > 0:#没有正数的话，就。。。
                    self.sub_left = i
                    self.sub_right = i
                    self.try_new = False
                    self.sum,sum = array[i],array[i]
            else:
                sum += array[i]
                if sum >self.sum:
                    self.sum = sum
                    self.sub_right = i
                if sum < 0:
                    self.try_new = True
        return self.sub_left,self.sub_right,self.sum
class MaxSubString_2():
    def __init__(self):
        self.sub_left = 0
        self.sub_right = 0
    def caculate(self,array):
        self.sum,sum = array[0],0
        for i in range(len(array)):
            if sum >0:# 说明这一段还可能继续变大
                sum+=array[i]
            else:
                sum = array[i]# 不能继续变大了
                self.sub_left,self.sub_right = i,i
            if self.sum < sum:# 变大时及时更新数据
                self.sum  = sum
                self.sub_right = i
        return self.sub_left,self.sub_right,self.sum





if __name__=="__main__":
    subHandler = MaxSubString()
    subHandler_1 = MaxSubString_2()
    print(subHandler.caculate([1,-2,3,10,-4,7,2,-48]))
    ## 全是负数就无法正确判断
    print(subHandler_1.caculate([1,-2,3,10,-4,7,2,-48]))
