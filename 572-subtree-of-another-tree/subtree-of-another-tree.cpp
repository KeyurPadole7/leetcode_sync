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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr) return p==q;

        bool lsame = isSameTree(p->left, q->left);
        bool rsame = isSameTree(p->right, q->right);

        return lsame && rsame && p->val==q->val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        bool lcheck = false, rcheck=false, check=false;

        check = isSameTree(root, subRoot);
        lcheck = isSubtree(root->left, subRoot);
        rcheck = isSubtree(root->right, subRoot);

        return check || lcheck || rcheck;
    }
};