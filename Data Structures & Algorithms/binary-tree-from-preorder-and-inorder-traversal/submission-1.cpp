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

    TreeNode* buildUtil(vector<int>& preorder, vector<int>& inorder, int l_pre,
        int r_pre, int l_in, int r_in) {
            if(r_pre < l_pre || r_in < l_in)
                return nullptr;
            int root_ind, root_val = preorder[l_pre];
            TreeNode* root = new TreeNode(root_val);
            for(root_ind = l_in;root_ind<=r_in;root_ind++) {
                if(inorder[root_ind] == root_val)
                    break;
            }
            root->left = buildUtil(preorder,inorder,l_pre+1,l_pre+root_ind-l_in,l_in,root_ind-1);
            root->right = buildUtil(preorder,inorder,l_pre+root_ind-l_in+1,r_pre,root_ind+1,r_in);
            return root;
        }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l_pre = 0, r_pre = preorder.size()-1;
        int l_in = 0, r_in = inorder.size()-1;
        return buildUtil(preorder,inorder,l_pre,r_pre,l_in,r_in);
    }
};
