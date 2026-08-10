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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int>> ans;
        vector<int> temp;
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            
            if(!currNode){
                ans.push_back(temp);
                temp.clear();
                if(q.empty()) break;
                q.push(NULL);
            } else {
                temp.push_back(currNode->val);
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }

        return ans;
    }
};
