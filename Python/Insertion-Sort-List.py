"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of linked list.
    @return: The head of linked list.
    """
    def insertionSortList(self, head):
        # write your code here
        pre = ListNode(0)
        while head is not None:
            cur = pre
            while (cur.next is not None) and cur.next.val < head.val:
                cur = cur.next
            temp = head.next
            head.next = cur.next
            cur.next = head
            head = temp
        return pre.next