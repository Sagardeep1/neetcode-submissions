# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def isSameTree(root, subRoot):
        if root == None and subRoot == None:
            return True
        elif root == None or subRoot == None:
            return False
        if root.val == subRoot.val and isSameTree(root.left, subRoot.left) and isSameTree(root.right, subRoot.right):
            return True
        return False

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None:
            return False
        if isSameTree(root, subRoot):
            return True
        l_val = self.isSubtree(root.left, subRoot)
        r_val = self.isSubtree(root.right, subRoot)
        if l_val or r_val:
            return True
        return False