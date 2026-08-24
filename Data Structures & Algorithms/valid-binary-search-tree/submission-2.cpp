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
    bool valid(TreeNode* node, long long l, long long r){
        if(!node) return true;
        if(node->val <= l || node->val >= r) return false;
        return (valid(node->left, l, node->val) && valid(node->right, node->val, r));
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
             