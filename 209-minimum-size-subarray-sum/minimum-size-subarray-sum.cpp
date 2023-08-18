class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curSum = 0;
        int l = 0;
        int u = 0;
        int n = nums.size();
        curSum = 0;
        int ans = 1e9;
        while(l < n && u < n){
            curSum += nums[u++];
            while(curSum >= target) {
                ans = min(ans, u - l);
                curSum -= nums[l++];
            }

        }
        return ans == 1e9 ? 0 : ans;
    }
};