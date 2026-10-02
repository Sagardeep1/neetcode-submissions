/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        unordered_map<Node*, Node*> mp;
        Node* ref = head;
        mp[head] = new Node(head->val);
        while(head->next) {
            Node* copy = mp[head];
            copy->next = new Node(head->next->val);
            mp[head->next] = copy->next;
            head = head->next;
        }
        head = ref;
        while(head) {
            Node* copy = mp[head];
            copy->random = (head->random ? mp[head->random] : NULL);
            head = head->next;
        }
        return mp[ref];
    }
};
