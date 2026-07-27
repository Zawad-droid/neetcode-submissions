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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }
    bool dfs(TreeNode* root, long long maxallow, long long minallow){
        if(root == nullptr) return true;
        if(root->val <= minallow) return false;
        if(root->val >= maxallow) return false;
        bool leftvalid = dfs(root->left, root->val, minallow);
        bool rightvalid = dfs(root->right, maxallow, root->val);
        return leftvalid && rightvalid;
    }
};
