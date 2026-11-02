# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return root
        l_tree = self.invertTree(root.left)
        r_tree = self.invertTree(root.right)
        root.left = r_tree
        root.right = l_tree
        return root
        