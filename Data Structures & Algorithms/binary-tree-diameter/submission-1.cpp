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
    int depthAndDiameter(TreeNode* root, int &maxDiameter){
        if(root == nullptr) return 0;
        int  left = depthAndDiameter(root->left, maxDiameter);
        int right = depthAndDiameter(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        depthAndDiameter(root, maxDiameter);
        return maxDiameter;
    }
};
