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
    TreeNode* pre = nullptr, * first = nullptr, * second = nullptr;

    void findpair(TreeNode* root){
        if(!root) return;
        findpair(root->left);
        if(pre && pre->val > root->val){
            if(!first) first = pre;
            second = root;
        }
        pre = root;
        findpair(root->right);
    }

    void recoverTree(TreeNode* root) {
        findpair(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};