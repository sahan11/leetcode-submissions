class DisjointSet {
    vector<int> rank, size, parent;
    vector<int> minDist;
    public:
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        minDist.resize(n + 1, INT_MAX);
        for(int i = 0;i<= n;i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        parent[node] = findUPar(parent[node]);
        minDist[node] = minDist[parent[node]];
        return parent[node];
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]) {
            // rank[ulp_u] += 1;
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_u] = ulp_v;  
            rank[ulp_v]++;
        }

    }

    void unionBySize(int u, int v, int wt) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        int min_wt = minDist[ulp_u] & minDist[ulp_v] & wt;
        minDist[ulp_u] = min_wt;
        minDist[ulp_v] = min_wt;

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];

        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

    int getMinDist(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u != ulp_v) return -1;
        else {
            return minDist[ulp_u];
        }
    }





};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet* ds = new DisjointSet(n);
        for(int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            ds->unionBySize(u, v, wt);
        }
        vector<int> ans;
        for(int i = 0;i<query.size();i++) {
            ans.push_back(ds->getMinDist(query[i][0], query[i][1]));
        }

        return ans;
    }
};