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
    
    int goodNodes(TreeNode* root, int maxSoFar = INT_MIN) {
        if(root == nullptr) return 0;
        int rs = 0;
        if(root->val >= maxSoFar){
            maxSoFar = root->val;
            rs = 1;
        }

        rs += goodNodes(root->left, maxSoFar);
        rs += goodNodes(root->right, maxSoFar);

        return rs;

    }
};
