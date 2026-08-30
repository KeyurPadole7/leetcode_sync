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
    vector<string> sol;
    void pth(TreeNode* root, string s){
        if(!root->left && !root->right){
            sol.emplace_back(s);
            return;
        }
        if(root->left) pth(root->left, s+"->"+to_string(root->left->val));
        if(root->right) pth(root->right, s+"->"+to_string(root->right->val));

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = to_string(root->val);
        pth(root, s);
        return sol;
    }
};