class Solution {
public:
    int time=0;
    vector<int> dt;
    vector<int> low;

    void dfs(int u, int par, vector<vector<int>>& adj, vector<vector<int>>& cc){
        dt[u] = low[u] = ++time;

        for(int v: adj[u]){
            if(dt[v] == -1){
                dfs(v, u, adj, cc);
                low[u] = min(low[u], low[v]);

                if(low[v] > dt[u]){
                    cc.push_back({u, v});
                }
            }
            else if(v != par){
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto uv: connections){
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.resize(n, -1);
        low.resize(n);

        vector<vector<int>> bridges;

        for(int u=0; u<n; u++){
            if(dt[u] == -1){
                dfs(u, -1, adj, bridges);
            }
        }

        return bridges;
    }
};