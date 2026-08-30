/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* c, vector<TreeNode*>& cc){
        if(!root) return false;
        cc.push_back(root);
        if(root == c) return true;
        if(path(root->left, c, cc) || path(root->right, c, cc)) return true;
        cc.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp, qq; 
        path(root, p, pp);
        path(root, q, qq);

        int i;
        for(i=0; i<pp.size()&&i<qq.size(); i++){
            if(pp[i]!=qq[i]) break;
        }

        return pp[i-1];
    }
};