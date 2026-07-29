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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inmap;
        for(int i = 0; i < inorder.size(); i++) inmap[inorder[i]] = i;
        int preIndex = 0;
        return dfs(inorder, preorder, 0, inorder.size() - 1, inmap, preIndex);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& preorder, int instart, int inend, unordered_map<int, int>& inmap, int& preIndex){
        if(instart > inend) return nullptr;
        int rootval = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootval);
        int rootIndex = inmap[rootval];
        root->left = dfs(inorder, preorder, instart, rootIndex - 1, inmap, preIndex);
        root->right = dfs(inorder, preorder, rootIndex + 1, inend, inmap, preIndex);
        return root;
    }
};
