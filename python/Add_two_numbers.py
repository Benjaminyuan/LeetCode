# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        len1 = 0
        num1,num2=0,0
        while l1 != None:
            num1 +=l1.val*pow(10,len1)
            l1=l1.next
            len1 +=1
        print(num1)
        len1 = 0
        while l2 != None:
             num2 +=l2.val*pow(10,len1)
             l2 = l2.next
             len1 +=1
        num3 = num1+num2
        elelist = list(str(num3))
        #这种方法行不通,数字太大的时候
        # while num3 >0 :
        #     elelist.append(num3%10)
        #     num3=int(num3/10)
        rnode = ListNode(0)
        Head = rnode
        while len(elelist)>1:
            rnode.val=int(elelist.pop())
            temp = ListNode(0)
            rnode.next = temp
            rnode= temp
        if len(elelist)==1:
            rnode.val=int(elelist.pop())
            rnode.next = None
        else:
            rnode.val=num3
            rnode.next = None
        return Head
        
