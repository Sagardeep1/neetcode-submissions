# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    count = 0

    def dfs(self, root, max_ele):
        if root == None:
            return
        if root.val >= max_ele:
            self.count += 1
        max_ele = max(max_ele, root.val)
        self.dfs(root.left, max_ele)
        self.dfs(root.right, max_ele)
        return


    def goodNodes(self, root: TreeNode) -> int:
        max_ele = -105
        self.dfs(root, max_ele)
        return self.count