class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<int> ans = maxDistance(points);
        return min(maxDistance(points, ans[1])[0], maxDistance(points, ans[2])[0]);
    }

    vector<int> maxDistance(vector<vector<int>> &ps, int skip = -1) {
        int n = ps.size();
        vector<int> sum = {INT_MAX, INT_MIN};
        vector<int> dif = {INT_MAX, INT_MIN};
        vector<int> sum_i = {0, 0};
        vector<int> dif_i = {0, 0};

        for(int i = 0;i<n;i++) {
            if(i == skip) continue;
            if(sum[0] > ps[i][0] + ps[i][1]) {
                sum[0] = ps[i][0] + ps[i][1];
                sum_i[0] = i;
            }
            if(sum[1] < ps[i][0] + ps[i][1]) {
                sum[1] = ps[i][0] + ps[i][1];
                sum_i[1] = i;
            }
            if(dif[1] < ps[i][0] - ps[i][1]) {
                dif[1] = ps[i][0] - ps[i][1];
                dif_i[1] = i;
            }
            if(dif[0] > ps[i][0] - ps[i][1]) {
                dif[0] = ps[i][0] - ps[i][1];
                dif_i[0] = i;
            }
            
        }

        if(sum[1] - sum[0] > dif[1] - dif[0]) {
            return {sum[1] - sum[0], sum_i[0], sum_i[1]};

        }
        else {
            return {dif[1] - dif[0], dif_i[0], dif_i[1]};
        }
    }
};