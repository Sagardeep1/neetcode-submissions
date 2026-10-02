# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        node = ListNode()
        ref = node
        while l1 and l2:
            sum = l1.val + l2.val + carry
            node.next = ListNode(sum % 10)
            carry = sum // 10
            l1 = l1.next
            l2 = l2.next
            node = node.next
        
        while l1:
            sum = l1.val + carry
            node.next = ListNode(sum % 10)
            carry = sum // 10
            l1 = l1.next
            node = node.next
        
        while l2:
            sum = l2.val + carry
            node.next = ListNode(sum % 10)
            carry = sum // 10
            l2 = l2.next
            node = node.next
        
        if carry != 0:
            node.next = ListNode(carry)
        
        return ref.next