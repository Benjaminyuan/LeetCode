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
        if not (head or  head.next):
            return head
        cur = head
        next = head.next
        head = next 
        cur.next = self.swapPairs(next.next)
        head.next = cur
        return head