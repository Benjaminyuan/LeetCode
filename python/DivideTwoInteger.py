class Solution:
    # def divide(self, dividend, divisor):
    #     """
    #     :type dividend: int
    #     :type divisor: int
    #     :rtype: int
    #     """
    # 这个太蠢了，可以追个加大减数的大小
    #     if dividend <=  pow(2,31)-1 and dividend >= -pow(2,31) and divisor <= pow(2,31) -1 and divisor >= -pow(2,31):
    #         a = abs(dividend)
    #         b = abs(divisor)
    #         result = 0
    #         operator = 1
    #         if abs(dividend+divisor)<(a+b):
    #             operator = 0
    #         # if a != dividend:
    #         #     a_is_Pos = False
    #         # else:
    #         #     a_is_Pos = True
    #         # if b != divisor:
    #         #     b_is_Pos = False
    #         # else  :
    #         #     b_is_Pos = True
    #         while(a >= b):
    #             a = a -b
    #             result+=1 
    #         # if (a_is_Pos and a_is_Pos) or ((not a_is_Pos)  and (not b_is_Pos)):
    #         #     return result
    #         # else :
    #         #     return -result 
    #         if operator:
    #             return result
    #         else :
    #             return -result
    #     else :
    #         return pow(2,31)-1
    def divide(self, dividend, divisor):     
        neg=( (dividend < 0) != (divisor < 0) )
        dividend = left = abs(dividend)
        divisor  = div  = abs(divisor)
        Q = 1
        ans = 0
        while left >= divisor:
            left -= div
            ans  += Q 
            Q    += Q
            div  += div
            if left < div:
                div = divisor
                Q = 1
        if neg:
            return max(-ans, -2147483648)
        else:
            return min(ans, 2147483647)
