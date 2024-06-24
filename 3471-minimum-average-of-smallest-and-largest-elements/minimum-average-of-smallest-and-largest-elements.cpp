class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int u = nums.size() - 1;
        double mini = 1e9;
        while(l < u) {
            double avg = (nums[l++] + nums[u--]) / 2.0;
            mini = min(mini, avg);
        }
        return mini;

    }
};