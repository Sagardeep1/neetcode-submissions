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

    bool dfsutil(TreeNode* root, int min, int max) {
        if(!root) return true;
        if(root->val > min && root->val < max)
        {
            return dfsutil(root->left,min,root->val) && 
                dfsutil(root->right,root->val,max);
        }
        else
            return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        int min = -1005, max = 1005;
        return dfsutil(root,min,max);
    }
};
