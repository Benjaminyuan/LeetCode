# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if lists:
            Cursor = lists[0]
            for i in range(len(lists)-1):
                Cursor = self.mergeTowList(Cursor,lists[i+1])
            return Cursor
        return lists
    def mergeTowList(self,List_1,List_2):
        if List_1 and List_2:
            Head = ListNode(None)
            Cursor = Head
            while List_1 and List_2:
                if List_1.val <= List_2.val:
                    Cursor.next = List_1
                    List_1 =List_1.next
                else:
                    Cursor.next = List_2
                    List_2 =List_2.next
                Cursor = Cursor.next
            if List_1:
                Cursor.next =  List_1
            else:
                Cursor.next = List_2
            return Head.next
        elif not List_1:
            return List_2
        else:
            return List_1
           
if __name__=="__main__":
    list_1 = ListNode(1)
    Head_1 = list_1
    numList = [4,5,7,8]
    for i in numList:
        list_1.next = ListNode(i)
        list_1 = list_1.next
        list_1.next = None
    list_2 = ListNode(1)
    Head_2 = list_2
    numList2 = [3,4,6,9]
    for i in numList2:
        list_2.next = ListNode(i)
        list_2 = list_2.next
        list_2.next = None
    Solu = Solution()
    res = Solu.mergeTowList(Head_1,Head_2)
    print(res)
    while res:
        print(res.val)
        res= res.next
