# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        reHead = ListNode(0)
        preHead = reHead
        preHead.next,cursor = head,head
        queue = []
        
        while cursor:
             queue.append(cursor)
             cursor = cursor.next
             if len(queue)==k:
                 while queue:
                     preHead.next = queue.pop()
                     preHead = preHead.next
        while queue:
            preHead.next = queue.pop(0)
            preHead = preHead.next
        preHead.next = None
        return reHead.next
       
            