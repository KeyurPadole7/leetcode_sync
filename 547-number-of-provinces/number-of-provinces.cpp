class Solution {
public:
    void dfs(int st, vector<vector<int>>& adj, vector<bool>& vis){
        vis[st] = true;
        for(int i=0; i<adj.size(); i++){
            if(adj[st][i] == 1 && !vis[i]){
                dfs(i, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        vector<bool> vis(adj.size(), false);

        int count = 0;
        for(int i=0; i<adj.size(); i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }

        return count;
    }
};