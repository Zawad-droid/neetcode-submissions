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

class Codec {
    void serializeHelper(TreeNode* root, string& data){
        if(root == nullptr){
            data.append("X,");
            return;
        }
        data.append(to_string(root->val) + ",");
        serializeHelper(root->left, data);
        serializeHelper(root->right, data);
    }
    TreeNode* deserializeHelper(vector<string>& tokens, int& index){
        if(tokens[index] == "X"){
            index++;
            return nullptr;
        }
        int token = stoi(tokens[index]);
        TreeNode* root = new TreeNode(token);
        index++;
        root->left = deserializeHelper(tokens, index);
        root->right = deserializeHelper(tokens, index);
        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serializeHelper(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string current;
        for(char c : data){
            if(c == ','){
                if(!current.empty()){
                    tokens.push_back(current);
                    current.clear();
                }
            }
            else{
                current += c;
            }
        }
        int index = 0;
        return deserializeHelper(tokens, index);
    }
};
