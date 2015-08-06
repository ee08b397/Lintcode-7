"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: A ListNode
    @return: A ListNode
    """
    def deleteDuplicates(self, head):
        # write your code here
        if head is None:
            return head
        p = head
        cur = head.next
        while cur is not None:
            if cur.val != p.val:
                p.next = cur
                p = p.next
            cur = cur.next
        p.next = None
        return head