class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<vector<int>>> adj(n + 1);
        for(int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<bool> vis(n, 0);

        vector<int> dist(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()) {
            int node = pq.top()[1];
            int distance = pq.top()[0];
            pq.pop();

            if(vis[node]) continue;
            else vis[node] = 1;
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int dis = it[1];
                if(distance + dis < disappear[adjNode] && distance + dis < dist[adjNode]) {
                    dist[adjNode] = distance + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        for(int i = 0;i<n;i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};