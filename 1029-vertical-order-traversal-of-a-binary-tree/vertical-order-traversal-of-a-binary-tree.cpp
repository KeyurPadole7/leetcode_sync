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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        // node <- row , col
        queue<pair<TreeNode*, pair<int,int>>> q;

        // col -> row -> vals
        map<int, map<int,multiset<int>>> mmm;

        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            mmm[j][i].insert(curr->val); 
            q.pop();
            if(curr->left) q.push({curr->left,{i+1,j-1}});
            if(curr->right) q.push({curr->right,{i+1,j+1}});
        }

        for(auto &[col, rowval]: mmm){
            vector<int> temp;
            for(auto &[row, st]: rowval){
                temp.insert(temp.end(), st.begin(), st.end());
            }
            result.emplace_back(temp);
        }

        return result;
    }
};