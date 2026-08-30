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
    int ip(TreeNode* root){
        while(root!=nullptr && root->left!=nullptr) root = root->left;
        return root->val;
    }

    int is(TreeNode* root){
        while(root!=nullptr && root->right!=nullptr) root = root->right;
        return root->val;
    }

    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        int mn = INT_MAX, mr = INT_MAX;
        if(root->right) mn = min(ip(root->right) - root->val, minDiffInBST(root->right));
        if(root->left) mr = min(root->val - is(root->left), minDiffInBST(root->left));
        return min(mn,mr);
    }
};