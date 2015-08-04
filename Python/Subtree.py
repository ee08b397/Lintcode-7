"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    # @param T1, T2: The roots of binary tree.
    # @return: True if T2 is a subtree of T1, or false.
    def issame(self, T1, T2):
        if T1 is None and T2 is None:
            return True
        elif T1 is None or T2 is None:
            return False
        if T1.val == T2.val:
            if self.issame(T1.left, T2.left) and self.issame(T1.right, T2.right):
                return True
        return False
    def isSubtree(self, T1, T2):
        # write your code here
        if T2 is None:
            return True
        if T1 is None:
            return False
        if T1.val == T2.val:
            if self.issame(T1, T2):
                return True
        if self.isSubtree(T1.left, T2):
            return True
        if self.isSubtree(T1.right, T2):
            return True
        return False