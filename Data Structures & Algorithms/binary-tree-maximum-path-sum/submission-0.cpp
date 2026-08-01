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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
    int dfs(TreeNode* root, int& max_sum){
        if(root == nullptr) return 0;
        int left = dfs(root->left, max_sum);
        int right = dfs(root->right, max_sum);
        if(left < 0) left = 0;
        if(right < 0) right  = 0;
        int sum = left + root->val + right;
        if(sum > max_sum) max_sum = sum;
        return root->val + max(left, right);

    }
};
