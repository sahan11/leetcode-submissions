class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<pair<int, int>> sum, diff;
        int n = points.size();
        for(int i = 0;i<points.size();i++) {
            sum.push_back({points[i][0] + points[i][1], i});
            diff.push_back({points[i][0] - points[i][1], i});
        }

        sort(sum.begin(), sum.end());
        sort(diff.begin(), diff.end());

        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            
            int left = 0;
            int right = n - 1;
            
            // move left and right pointer if it is pointing at ith point
            if(sum[left].second == i) left++;
            if(sum[right].second == i) right--;
            
            // get maximum difference between two different values in the sum array
            int sumVal = sum[right].first - sum[left].first;
            
            left = 0;
            right = n - 1;
            
            // move left and right pointer if it is pointing at ith point
            if(diff[left].second == i) left++;
            if(diff[right].second == i) right--;
            
            // get maximum difference between two different values in the sum array
            int diffVal = diff[right].first - diff[left].first;
            
            // update ans accordingly
            ans = min(ans, max(sumVal, diffVal));
        }
                
        return ans;
    }
};