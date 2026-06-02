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
        queue<TreeNode*> qu;
        string res;
        qu.push(root);
        while(!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            if(!node) {
                res += "N*";
                continue;
            }
            res += (to_string(node->val) + "*");
            qu.push(node->left);
            qu.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string tmp;
        getline(ss,tmp,'*');
        if(tmp == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(getline(ss,tmp,'*')) {
            TreeNode* node = qu.front();
            qu.pop();
            if(tmp != "N") {
                node->left = new TreeNode(stoi(tmp));
                qu.push(node->left);
            }
            getline(ss,tmp,'*');
            if(tmp != "N") {
                node->right = new TreeNode(stoi(tmp));
                qu.push(node->right);
            }
        }
        return root;
    }
};
