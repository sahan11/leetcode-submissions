class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int i = 0;i<hCut.size();i++) {
            pq.push({hCut[i], 0});
        }

        for(int i = 0;i < vCut.size();i++) {
            pq.push({vCut[i], 1});
        }

        int rowMul = 1;
        int colMul = 1;
        long long ans = 0;
        while(!pq.empty()) {
            int cost = pq.top().first;
            int cut = pq.top().second;
            pq.pop();

            if(cut == 0) {
                ans += 1LL* cost * colMul;
                rowMul++;
            }
            else {
                ans += 1LL * cost * rowMul;
                colMul++;
            }
        }

        return ans;
    }
};