class Solution {
public:
    int f(int ind, int lastInd, vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(ind == n){
            return 0;
        }

        if(dp[ind][lastInd + 1] != -1) return dp[ind][lastInd + 1];
        int take = 0;
        int not_Take = 0;
        not_Take = f(ind + 1, lastInd, nums, dp);
        if(lastInd == -1 || nums[ind] > nums[lastInd]) take = 1 + f(ind + 1, ind, nums, dp);
        return dp[ind][lastInd + 1] = max(take, not_Take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 2, -1));
        return f(0, -1, nums, dp);
    }
};