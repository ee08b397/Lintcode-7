"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    """
    @param root: The root of the binary search tree.
    @param node: insert this node into the binary search tree.
    @return: The root of the new binary search tree.
    """
    def insertNode(self, root, node):
        # write your code here
        if root is None:
            return node
        cur = root
        while cur is not None:
            if node.val == cur.val:
                return root
            elif cur.val < node.val:
                if cur.right is None:
                    cur.right = node
                    return root
                else:
                    cur = cur.right
            elif cur.val > node.val:
                if cur.left is None:
                    cur.left = node
                    return root
                else:
                    cur = cur.left
        return root