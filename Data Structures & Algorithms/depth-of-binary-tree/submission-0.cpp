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
    int dfs(TreeNode* root){
        if(!root) return 0;

        int leftHt = dfs(root->left);
        int rightHt = dfs(root->right);

        return 1 + max(leftHt, rightHt);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
