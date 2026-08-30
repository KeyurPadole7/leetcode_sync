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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root, 0});

        int mxw = 0;

        while(!q.empty()){
            int n = q.size();
            mxw = max(mxw, int(q.back().second-q.front().second+1));

            for(int i=0; i<n; i++){
                TreeNode* curr = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left, idx*2+1});
                if(curr->right) q.push({curr->right, idx*2+2});
            }
        }

        return mxw;
    }
};