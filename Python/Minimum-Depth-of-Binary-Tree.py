class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def minDepth(self, root):
        # write your code here
        if root is None:
            return 0
        if root.left is not None and root.right is not None:
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        if root.left is None and root.right is None:
            return 1
        if root.left is not None:
            return self.minDepth(root.left) + 1
        else:
            return self.minDepth(root.right) + 1