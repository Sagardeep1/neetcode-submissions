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

    ListNode* reverse_ll(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* back_ptr = nullptr;
        while(head) {
            ListNode* next_ptr = head->next;
            head->next = back_ptr;
            back_ptr = head;
            head = next_ptr;
        }
        return back_ptr;
    }

public:
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next)
            return;
        ListNode* slow, *fast, *tail;
        slow = fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        tail = slow->next;
        slow->next = nullptr;
        tail = reverse_ll(tail);
        ListNode* ref = head;
        while(tail) {
            ListNode* ptr = head->next;
            head->next = tail;
            tail = tail->next;
            head->next->next = ptr;
            head = ptr;
        }
        head = ref;
    }
};
