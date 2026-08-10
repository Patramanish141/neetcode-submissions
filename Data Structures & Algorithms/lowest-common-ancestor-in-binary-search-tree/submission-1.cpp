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
    // bool rootToNodePath(TreeNode* root, int n, vector<TreeNode*> &path){
    //     if(!root) return false;

    //     path.push_back(root);
    //     if(root->val == n) return true;

    //     bool isLeft = rootToNodePath(root->left, n, path);
    //     if(isLeft) return true;
    //     bool isRight = rootToNodePath(root->right, n, path);
    //     if(isRight) return true;

    //     //if path not found
    //     path.pop_back();
    //     return false;

    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA) return root;//got p & q on below the root

        return leftLCA == NULL ? rightLCA : leftLCA;
    }
};
