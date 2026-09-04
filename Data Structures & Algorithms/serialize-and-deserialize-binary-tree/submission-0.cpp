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
public:
    void serializeHelper(TreeNode* root, string& s){
        if(!root){
            s += "N,";      
            return;
        }
        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    
    TreeNode* deserializeHelper(string& data, int& i){
        if(i >= data.length()) return nullptr;

        if(data[i] == 'N'){
            i+=2;
            return nullptr;
        }
        int start = i;
        while(i < data.length() && data[i] != ','){
            ++i;
        }
        ++i;
        int val = stoi(data.substr(start, i - start     ));
        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(data, i);
        node->right = deserializeHelper(data, i);
        return node;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s;
       serializeHelper(root, s);
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        TreeNode* root = deserializeHelper(data, i);
        return root;
    }
};
