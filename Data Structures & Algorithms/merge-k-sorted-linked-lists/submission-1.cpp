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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        return mergesort(lists,0,lists.size()-1);
    }

    ListNode* mergesort(vector<ListNode*>& lists, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        int mid = (l+r)/2;
        ListNode* left = mergesort(lists,l,mid);
        ListNode* right = mergesort(lists,mid+1,r);
        return merge(left,right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* ptr = new ListNode();
        ListNode* bkp = ptr;
        while(left && right) {
            if(left->val < right->val) {
                ptr->next = left;
                left = left->next;
            }
            else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        while(left) {
            ptr->next = left;
            left = left->next;
            ptr = ptr->next;
        }
        while(right) {
            ptr->next = right;
            right = right->next;
            ptr = ptr->next;
        }
        return bkp->next; 
    }
};
