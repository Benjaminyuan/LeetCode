class Solutwion:
    def myAtoi(self, strs):
        """
        :type str: str
        :rtype: int
        """
        string = strs.strip()
        if string:
            last =0
            intRange = [ str(i) for i in range(0,10)]
            if string[0] in intRange or string[0] in ['-','+']:
                for i in range(1,len(string)):
                    if string[i] in intRange:
                        last =i
                    else:
                        break
                max = pow(2,31)-1
                min = -pow(2,31)
                if last and int(string[0:last+1]) in range(min,max):
                    return int(string[0:last+1])
                elif last and string[0]=='-':
                    return min
                elif last:
                    return max
                elif string[0] in intRange:
                    return int(string[0])
            return 0
        else:
            return 0


