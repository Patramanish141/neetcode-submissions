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
    int dfs(TreeNode* node, int maxTill){
        if(!node) return 0;

        int res = (node->val >= maxTill) ? 1 : 0;
        maxTill = max(maxTill, node->val);
        res += dfs(node->left, maxTill);
        res += dfs(node->right, maxTill);

        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
