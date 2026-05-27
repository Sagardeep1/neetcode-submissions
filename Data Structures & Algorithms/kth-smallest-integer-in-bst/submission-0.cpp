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

    int dfsutil(TreeNode* root, int& k, int& rank) {
        if(!root) return -1;
        int l = dfsutil(root->left,k,rank);
        if(l != -1) return l;
        if(rank == k) return root->val;
        rank++;
        int r = dfsutil(root->right,k,rank);
        if(r != -1) return r;
        return -1;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int rank = 1;
        int ans = dfsutil(root,k,rank);
        return ans;
    }
};
