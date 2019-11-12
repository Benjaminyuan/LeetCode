# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        cursor_1,cursor_2 = head,head
        for i in range(0,n):
                cursor_2 = cursor_2.next
        if cursor_2 is None:
            head = head.next
            return head
        while cursor_2.next:#边界条件！！！！！！整合边界条件！！！
            cursor_2 =cursor_2.next
            cursor_1 = cursor_1.next
        cursor_1.next = cursor_1.next.next
        return head
if __name__=="__main__":
    nums = [1,2,3]
    head = ListNode(0)
    head_real = head
    for num in nums:
        head.next = ListNode(num)
        head = head.next
    s = Solution()
    s.removeNthFromEnd(head_real.next,3)
    while head_real:
        print(head_real.val)
        head_real = head_real.next
    