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
    int ans = -1005;

    int dfsutil(TreeNode* root) {
        if(!root) return 0;
        int l = dfsutil(root->left);
        int r = dfsutil(root->right);
        cout<<l<<' '<<r<<endl;
        ans = max(ans,root->val + max(0,l) + max(0,r));
        //cout<<ans<<'*';
        return root->val + max(0,max(l,r));
    }

public:
    int maxPathSum(TreeNode* root) {
        dfsutil(root);
        return ans;
    }
};
