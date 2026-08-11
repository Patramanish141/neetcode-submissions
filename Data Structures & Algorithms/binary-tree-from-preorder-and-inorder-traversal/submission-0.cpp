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
    int index = 0;
    unordered_map<int, int> m;

    TreeNode* helper(vector<int> &preorder, int l, int r){
        if(l > r) return nullptr;

        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = m[rootVal];//index of curr Root

        root->left = helper(preorder, l, mid-1);
        root->right = helper(preorder, mid+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) m[inorder[i]] = i;
        return helper(preorder, 0, inorder.size()-1);
    }
};