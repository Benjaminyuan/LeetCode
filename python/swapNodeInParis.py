# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head:
            Head = ListNode(0)
            first = Head
            Head.next = head
            mid = first.next
            last = mid.next
            while last:
                first.next = last
                first = last
                last = last.next
                first.next = mid
                mid.next = last
                first = mid
                mid= last
                if last:
                    last= last.next
            return Head.next
