/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 1;
        ListNode* ref = head, *slow, *fast;
        slow = fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            sz++;
        }
        if(fast->next) 
            sz *= 2;
        else sz = sz*2 - 1;
        
        if(n == sz) {
            return head->next;
        }
        int count = 0;
        while(1) {
            count++;
            if(count == sz-n) break;
            head = head->next;
        }
        head->next = head->next->next;
        return ref;
    }
};
