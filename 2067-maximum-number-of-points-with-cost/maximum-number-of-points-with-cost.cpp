class Solution {
public:
    long long f(vector<vector<int>> &points) {
        int n = points.size();
        vector<long long> prev(points[0].size());
        for(int i = 0;i<prev.size();i++) {
            prev[i] = points[0][i];
        }
        vector<long long> cur(prev.size());
        for(int i = 1;i<n;i++) {
            vector<long long> left = prev;
            vector<long long> right = prev;
            for(int j = 0;j<prev.size();j++) {
                left[j] = left[j] + j;
                right[j] = right[j] - j;
            }
            for(int j = 1;j<prev.size();j++) {
                left[j] = max(left[j], left[j - 1]);
            }
            for(int j = prev.size() - 2;j>=0;j--) {
                right[j] = max(right[j], right[j + 1]);
            }

            for(int j = 0;j<prev.size();j++) {
                cur[j] = max(left[j] - j, right[j] + j) + points[i][j];
            }
            prev = cur;
        }

        return *max_element(prev.begin(), prev.end());


    }
    
    long long maxPoints(vector<vector<int>>& points) {
        return f(points);
    }
};