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
    bool isValidBST(TreeNode* root) {
        int min = -1005, max = 1005;
        queue<tuple<TreeNode*, int, int>> qu;
        qu.push(make_tuple(root,min,max));
        while(!qu.empty()) {
            auto [node,min,max] = qu.front();
            qu.pop();
            if(!(node->val > min && node->val < max))
                return false;
            if(node->left)
                qu.push(make_tuple(node->left,min,node->val));
            if(node->right)
                qu.push(make_tuple(node->right,node->val,max));
        }
        return true;
    }
};
