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

    void dfsutil(TreeNode* root, vector<vector<int>>& ans, int depth) {
        if(!root) return;
        if(depth == ans.size())
            ans.push_back({});
        ans[depth].push_back(root->val);
        dfsutil(root->left,ans,depth+1);
        dfsutil(root->right,ans,depth+1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfsutil(root,ans,0);
        return ans;
    }
};
