class Solution {
public:
    vector<int> topoSort(vector<vector<int>> edges, int k) {
        vector<vector<int>> adj(k + 1);
        for(int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        int n = k;
        vector<int> inDegree(n + 1, 0);
        for(int i = 1;i<=n;i++) {
            for(auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 1;i<=n;i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(ans.size() != n) {
            return {-1};
        }
        else return ans;

        
    }

    vector<int> reverseIndex(vector<int> arr) {
        if(arr[0] == -1) return {-1};
        int n = arr.size();
        vector<int> ans(n + 1);

        for(int i = 0;i<n;i++) {
            ans[arr[i]] = i;
        }

        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> topoRow = reverseIndex(topoSort(rowConditions, k));
        if(topoRow[0] == -1) return {};
        for(auto it : topoRow) {
            cout<<it<<" ";
        }cout<<endl;


        vector<int> topoCol = reverseIndex(topoSort(colConditions, k));
        if(topoCol[0] == -1) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 1;i<=k;i++) {
            ans[topoRow[i]][topoCol[i]] = i;
        }

        
        return ans;
    }
};