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
    @param n: An integer.
    @return: Nth to last node of a singly linked list.
    """
    def nthToLast(self, head, n):
        # write your code here
        pre = TreeNode(0)
        pre.next = head
        fast = pre
        for i in range(n):
            fast = fast.next
        slow = pre
        while fast is not None:
            slow = slow.next
            fast = fast.next
        return slow