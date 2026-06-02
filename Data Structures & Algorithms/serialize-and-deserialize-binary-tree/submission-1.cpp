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

class Codec {

    void dfsserialize(TreeNode* root, vector<string>& vec) {
        if(!root) {
            vec.push_back("N");
            return;
        }
        vec.push_back(to_string(root->val));
        dfsserialize(root->left,vec);
        dfsserialize(root->right,vec);
        return;
    }

    TreeNode* dfsdeserialize(vector<string>& vec, int& ind) {
        if(vec[ind] == "N") {
            ind++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vec[ind++]));
        node->left = dfsdeserialize(vec,ind);
        node->right = dfsdeserialize(vec,ind);
        return node;
    }

    string join(const vector<string>& vec, const string& lim) {
        ostringstream res;
        for(const auto& i:vec) {
            if(&i != &vec[0])
                res << lim;
            res << i;
        }
        return res.str();
    }

    vector<string> split(const string& data, const char& lim) {
        vector<string> vec;
        stringstream ss(data);
        string item;
        while(getline(ss,item,lim)) {
            vec.push_back(item);
        }
        return vec;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> vec;
        dfsserialize(root,vec);
        return join(vec, "*");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec = split(data,'*');
        int ind = 0;
        return dfsdeserialize(vec, ind);
    }
};
