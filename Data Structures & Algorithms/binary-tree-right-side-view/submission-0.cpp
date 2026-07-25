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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> myq;
        vector<int> res;
        myq.push(root);
        while(!myq.empty()){
            int levelsize = myq.size();
            for(int i = 0; i < levelsize; i++){
                TreeNode* curr = myq.front();
                myq.pop();
                if(i == levelsize - 1) res.push_back(curr->val);
                if(curr->left != nullptr) myq.push(curr->left);
                if(curr->right != nullptr) myq.push(curr->right);
            }
        }
        return res;
    }
};
