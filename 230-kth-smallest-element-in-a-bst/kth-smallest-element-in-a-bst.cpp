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
    int order = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        if(root->left){
            int lfv = kthSmallest(root->left, k);
            if(lfv != -1) return lfv;
        }
        if(order+1 == k) return root->val;
        order++;
        if(root->right){
            int rtv = kthSmallest(root->right, k);
            if(rtv != -1) return rtv;
        }

        return -1;
    }
};