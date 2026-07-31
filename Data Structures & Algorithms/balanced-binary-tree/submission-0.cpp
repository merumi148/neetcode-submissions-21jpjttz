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
    bool rs =true;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        vector<int> sample = {-1, 0 ,1};
        int left = dfs(root->left);
        int right = dfs(root->right);

        auto it = find(sample.begin(), sample.end(), left - right);
        if(it == sample.end()) rs = false;

        
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return rs;
    }
};
