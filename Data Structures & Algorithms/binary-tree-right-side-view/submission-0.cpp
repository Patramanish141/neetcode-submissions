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
    void dfs(TreeNode* node, int currLevel, map<int, TreeNode*> &m){
        if(!node) return;

        // ans.push_back(node->val);
        if(m.count(currLevel) == 0){
            m[currLevel] = node;
        }
        
        if(node->right){
            dfs(node->right, currLevel+1, m);
        }
        if(node->left){
            dfs(node->left, currLevel+1, m);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, TreeNode*> m;//will store node and its level
        vector<int> order;

        dfs(root, 0, m);

        for(auto it : m){
            order.push_back(it.second->val);
        }

        return order;
    }
};
