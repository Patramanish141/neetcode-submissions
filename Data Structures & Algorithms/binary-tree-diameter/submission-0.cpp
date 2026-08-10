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
    pair<int, int> diam(TreeNode* root){
        if(!root) return {0, 0};//diam, height

        auto leftInfo = diam(root->left);
        auto rightInfo = diam(root->right);

        int currDiam = leftInfo.second + rightInfo.second + 1;

        int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
        int finalHt = max(leftInfo.second ,rightInfo.second) + 1;

        return {finalDiam, finalHt};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diam(root).first - 1;  //because we are counting number of nodes

    }
};
