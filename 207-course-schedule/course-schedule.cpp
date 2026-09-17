class Solution {
public:
    class Graph{
        int V;
        list<int> *l;

    public:
        Graph(int v){
            V = v;
            l = new list<int> [v];
        }

        void makeGraph(int u, int v){
            l[u].push_back(v);
        }

        bool dfs(int source, vector<bool>& vis, vector<bool>& path){
            vis[source] = true;
            path[source] = true;

            for(int neighbour: l[source]){
                if(!vis[neighbour]){
                    if(dfs(neighbour, vis, path)) return true;
                }else if(vis[neighbour] && path[neighbour]) return true;
            }
            path[source] = false;
            return false;
        }

        bool isCycle(){
            vector<bool> vis(V, false);
            vector<bool> path(V, false);

            for(int i=0; i<V; i++){
                if(!vis[i]){
                    if(dfs(i, vis, path)) return true;
                }
            }
            return false;
        }
    };

    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        Graph* g = new Graph(numCourses);
        for(auto vtr: pr){
            g->makeGraph(vtr[1], vtr[0]);
        }
        return !g->isCycle();
    }
};