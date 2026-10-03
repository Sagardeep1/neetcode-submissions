# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root):
        if root is None:
            return (0, True)
        l_height, l_ans = self.dfs(root.left)
        r_height, r_ans = self.dfs(root.right)
        
        if l_ans is False or r_ans is False or abs(l_height - r_height) > 1:
            return (max(l_height, r_height) + 1, False)
        
        return (max(l_height, r_height) + 1, True)

    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        height, ans = self.dfs(root)
        return ans