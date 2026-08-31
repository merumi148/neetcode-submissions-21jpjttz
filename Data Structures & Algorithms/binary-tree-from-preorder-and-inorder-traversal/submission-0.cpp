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
    unordered_map<int, int> mp;
    int preorder_index = 0;
    TreeNode* arrayToTree(vector<int> &preorder, int l, int r){
        if(l > r) return nullptr;

        int root_val = preorder[preorder_index];
        preorder_index++;
        TreeNode* root = new TreeNode(root_val);

        int inorder_index = mp[root_val];

        root->left = arrayToTree(preorder, l, inorder_index - 1);
        root->right = arrayToTree(preorder, inorder_index + 1, r);

        return root;
    }     
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        for(int i = 0; i < preorder.size(); ++i){
            mp[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, preorder.size() - 1);

    }
};
