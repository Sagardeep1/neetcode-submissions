/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            vector<int> list;
            queue<TreeNode*> tmp;
            int ref = qu.size();
            for(int i=0;i<ref;i++) {
                TreeNode* node = qu.front();
                qu.pop();
                list.push_back(node->val);
                if(node->left) tmp.push(node->left);
                if(node->right) tmp.push(node->right);
            }
            qu = tmp;
            ans.push_back(list);
        }
        return ans;
    }
};
