class Solution {
public:
    int check(int ind, int curSum, vector<int> &rewardValues, vector<vector<int>> &dp) {
        if(ind == rewardValues.size()) return curSum;
        if(dp[ind][curSum] != -1) return dp[ind][curSum];
        int sum = 0;
        int take = 0;
        int not_Take = 0;

        if(rewardValues[ind] > curSum) take = check(ind + 1, curSum + rewardValues[ind], rewardValues, dp);
        not_Take = check(ind + 1, curSum, rewardValues, dp);

        return dp[ind][curSum] = max(take, not_Take);

        
        
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        // int sum = 0;
        int n = rewardValues.size();
        
        vector<vector<int>> dp(n, vector<int>(4000, -1));
        return check(0, 0, rewardValues, dp);
        
    }
};