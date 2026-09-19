class Solution {
public:
    class Edge {
    public:
        int u, v, wt;
        Edge(int u, int v, int wt) {
            this->u = u;
            this->v = v;
            this->wt = wt;
        }

        // Reversed to make std::priority_queue act as a min-heap
        bool operator<(const Edge& other) const {
            return this->wt > other.wt;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<Edge> pq;
        vector<bool> inMST(n, false);

        // Start from node 0 with a weight of 0
        pq.push(Edge(0, 0, 0));

        int ans = 0;
        int nodesConnected = 0;

        while (!pq.empty() && nodesConnected < n) {
            Edge e = pq.top();
            pq.pop();

            // Skip if destination is already part of the MST
            if (inMST[e.v]) continue;

            // Include vertex e.v in the MST
            inMST[e.v] = true;
            ans += e.wt;
            nodesConnected++;

            // Push edges from the newly added vertex to all unvisited vertices
            for (int j = 0; j < n; j++) {
                if (!inMST[j]) {
                    int wt = abs(points[e.v][0] - points[j][0]) + abs(points[e.v][1] - points[j][1]);
                    pq.push(Edge(e.v, j, wt));
                }
            }
        }

        return ans;
    }
};