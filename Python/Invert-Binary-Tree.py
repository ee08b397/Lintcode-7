"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    # @param root: a TreeNode, the root of the binary tree
    # @return: nothing
    def invertBinaryTree(self, root):
        # write your code here
        if root is None:
            return
        temp = root.left
        root.left = root.right
        root.right = temp
        self.invertBinaryTree(root.left)
        self.invertBinaryTree(root.right)