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
        if(lists.size() == 0) return nullptr;
        ListNode* ptr = new ListNode();
        bool flag = true;
        int ref, ind;
        ListNode* node = nullptr, *bk = ptr;
        while(flag) {
            flag = false;
            ref = 1005;
            for(int i=0;i<lists.size();i++) {
                ListNode* ll = lists[i];
                if(!ll) continue;
                flag = true;
                if(ll->val < ref) {
                    ref = ll->val;
                    node = ll;
                    ind = i;
                }
            }
            if(!flag) break;
            ptr->next = node;
            ptr = ptr->next;
            lists[ind] = lists[ind]->next;
        }
        ptr->next = nullptr;
        return bk->next;
    }
};
