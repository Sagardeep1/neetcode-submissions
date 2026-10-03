# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        qu = deque()
        ans = []
        qu.append(root)
        
        while qu:
            qu_sz = len(qu)
        
            for _ in range(qu_sz):
                node = qu.popleft()
                if node.left:
                    qu.append(node.left)
                if node.right:
                    qu.append(node.right)
            
            ans.append(node.val)
        
        return ans
