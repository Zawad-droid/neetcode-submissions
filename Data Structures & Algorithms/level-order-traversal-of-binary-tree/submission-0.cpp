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
        if(root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> myq;
        myq.push(root);
        TreeNode* curr = root;
        while(!myq.empty()){
            vector<int> levelorder;
            int levelsize = myq.size();
            for(int i = 0; i < levelsize; i++){
                curr = myq.front();
                myq.pop();
                levelorder.push_back(curr->val);
                if(curr->left != nullptr) myq.push(curr->left);
                if(curr->right != nullptr) myq.push(curr->right);
            }
            res.push_back(levelorder);
        }
        return res;
    }
};
