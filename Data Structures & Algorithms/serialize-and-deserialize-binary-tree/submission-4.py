# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Codec:
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        string = ""
        def dfs(root):
            nonlocal string
            if root is None:
                string += "#,"
                return
            
            string += (str(root.val) + ",")
            dfs(root.left)
            dfs(root.right)

        dfs(root)
        return string
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        vals = data.split(',')
        self.ind = 0

        def dfs():
            if vals[self.ind] == '#':
                self.ind += 1
                return None
            
            node = TreeNode(vals[self.ind])
            self.ind += 1
            node.left = dfs()
            node.right = dfs()
            return node
        
        root = dfs()
        return root