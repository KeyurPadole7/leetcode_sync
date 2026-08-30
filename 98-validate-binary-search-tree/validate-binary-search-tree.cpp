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
    bool isv(TreeNode* root, long long minr, long long maxr){
        if(root == nullptr) return true;
        bool lv = true, rv = true;
        lv = minr<root->val && isv(root->left, minr, root->val);
        rv = root->val<maxr && isv(root->right, root->val, maxr);
        return lv && rv;
    }
    bool isValidBST(TreeNode* root) {
        return isv(root, LLONG_MIN, LLONG_MAX);
    }
};