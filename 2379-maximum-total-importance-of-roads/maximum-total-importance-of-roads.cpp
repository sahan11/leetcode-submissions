class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> inDegree(n);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];

            inDegree[u].first++;
            inDegree[u].second = u;
            inDegree[v].first++;
            inDegree[v].second = v;
        }

        sort(inDegree.begin(), inDegree.end());

        for(int i = 0;i<n;i++) {
            cout<<"("<<inDegree[i].first<<", "<<inDegree[i].second<<")"<<endl;
        }
        long long sum = 0;
        for(int i = 0;i<n;i++) {
            sum += 1LL * inDegree[i].first * (i + 1);
        }

        return sum;
    }
};