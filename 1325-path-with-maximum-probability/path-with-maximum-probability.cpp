class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        vector<int> vis(n, 0);
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({1, start_node});
        vector<double> prob(n, 0);

        while(!pq.empty()) {
            int node = pq.top().second;
            double dist = pq.top().first;
            pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;

            for(auto it : adj[node]) {
                int adjNode = it.second;
                double dis = it.first;

                if(prob[adjNode] < dist * dis){
                    prob[adjNode] = dist * dis;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }

        return prob[end_node];
    }
};