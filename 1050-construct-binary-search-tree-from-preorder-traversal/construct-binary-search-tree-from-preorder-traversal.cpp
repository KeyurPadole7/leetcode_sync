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
    int search(vector<int>& preorder, int x, int left, int right){
        for(int i=left; i<=right; i++){
            if(preorder[i]>x) return i;
        }
        return right+1;
    }
    TreeNode* helper(vector<int>& preorder, int left, int right){
        if(left>right) return nullptr;
        TreeNode* curr = new TreeNode(preorder[left]);
        int idx = search(preorder, preorder[left], left, right);
        left++;
        curr->left = helper(preorder, left, idx-1);
        curr->right = helper(preorder, idx, right);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
    // TreeNode* helper(vector<int>& preorder,int& i, int father){
    //     if(i >= preorder.size() || preorder[i] > father) return nullptr;
    //     TreeNode* curr = new TreeNode(preorder[i]);
    //     i++;

    //     curr->left = helper(preorder, i, curr->val);
    //     curr->right = helper(preorder, i, father);

    //     return curr;
    // }

    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     int i=0;
    //     return helper(preorder, i, INT_MAX);
    // }
};