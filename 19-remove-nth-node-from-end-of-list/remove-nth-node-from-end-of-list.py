# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        sz = 0
        temp = head
        while(temp):
            temp = temp.next
            sz += 1
        
        temp = head
        iteration = sz - n - 1
        if(iteration==-1):
            return head.next

        while(iteration>0):
            temp = temp.next
            iteration -= 1

        if temp == head and temp.next == None:
            return None

        temp.next = temp.next.next

        return head