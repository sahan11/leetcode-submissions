class Solution {
public:
    
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind == 1) return max(nums[0], nums[1]);
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(f(ind - 1, nums, dp), nums[ind] + f(ind - 2, nums, dp));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
        
    }
};