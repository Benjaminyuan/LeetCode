class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        list_1 = []
        list_2 = []
        
        
        while l1:
            list_1.insert(0, str(l1.val))
            l1 = l1.next
            
        while l2:
            list_2.insert(0, str(l2.val))
            l2 = l2.next
            
        sum_1 = int(''.join(list_1))
        sum_2 = int(''.join(list_2))
        
        total = sum_1 + sum_2
        total = str(total)
        
        reversed_list = list(reversed(list(total)))
        
        reversed_list = [int(x) for x in reversed_list]
        
        return reversed_list