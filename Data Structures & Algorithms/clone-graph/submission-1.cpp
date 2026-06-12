/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        unordered_map<Node*,Node*> mp;
        Node* root = new Node(node->val);
        mp[node] = root;
        queue<Node*> qu;
        qu.push(node);
        while(!qu.empty()) {
            Node* node = qu.front();
            qu.pop();
            for(auto ele:node->neighbors) {
                if(mp.find(ele) == mp.end()) {
                    mp[ele] = new Node(ele->val);
                    qu.push(ele);
                }
                mp[node]->neighbors.push_back(mp[ele]);
            }
        }
        return mp[node];
    }
};
