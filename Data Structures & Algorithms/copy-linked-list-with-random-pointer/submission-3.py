"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return head
        
        cur = head
        while cur:
            copy = Node(cur.val)
            copy.next = cur.random
            cur.random = copy
            cur = cur.next
        
        cur = head
        ans = cur.random
        while cur:
            copy = cur.random
            copy.random = copy.next.random if copy.next else None
            #copy.next = cur.next.random if cur.next else None
            cur = cur.next

        cur = head
        while cur:
            copy = cur.random
            cur.random = copy.next
            copy.next = cur.next.random if cur.next else None
            cur = cur.next
        
        return ans
