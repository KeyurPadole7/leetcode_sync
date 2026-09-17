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

        stack<int> s;

        bool dfs(int source, vector<bool>& vis, vector<bool>& path){
            vis[source] = true;
            path[source] = true;

            for(auto ngh: l[source]){
                if(!vis[ngh]){
                    if(dfs(ngh, vis, path)) return true;
                }else if(vis[ngh] && path[ngh]) return true;
            }
            s.push(source);
            path[source] = false;
            return false;
        }

        bool iscycle(){
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
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        Graph g(numCourses);

        for(auto vtr: pr){
            g.makeGraph(vtr[1], vtr[0]);
        }

        vector<int> v;

        if(g.iscycle()) return v;

        while(!g.s.empty()){
            v.push_back(g.s.top());
            g.s.pop();
        }

        return v;

    }
};