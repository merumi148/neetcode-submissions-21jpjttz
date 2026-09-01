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
    int sum;
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        left = max(left, 0);
        right = max(right, 0);

        sum = max(sum, root->val + left + right);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        dfs(root);

        return sum;


    }
};
