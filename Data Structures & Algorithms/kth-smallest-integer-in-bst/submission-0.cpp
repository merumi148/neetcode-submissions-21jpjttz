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
    void dfs(TreeNode* node, vector<int> &vt){
        if(!node) return;
        vt.push_back(node->val);
        dfs(node->left, vt);
        dfs(node->right, vt);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vt;
        dfs(root, vt);
        sort(vt.begin(), vt.end());

        return vt[k - 1];

    }
};
