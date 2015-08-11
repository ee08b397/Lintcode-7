# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param l1: the first list
    # @param l2: the second list
    # @return: the sum list of l1 and l2
    def helper(self, l1, l2, res):
        if l1 is None and l2 is None and res == 0:
            return None
        data = res
        if l1 is not None:
            data += l1.val
            l1 = l1.next
        if l2 is not None:
            data += l2.val
            l2 = l2.next
        node = ListNode(data % 10)
        node.next = self.helper(l1, l2, data / 10)
        return node

    def addLists(self, l1, l2):
        # write your code here
        return self.helper(l1, l2, 0)