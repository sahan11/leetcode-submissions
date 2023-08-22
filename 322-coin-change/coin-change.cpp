class Solution {
public:
    int f(int ind, vector<int> &coins, int target,vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(ind == 0){
            if(target % coins[ind] == 0) return (target / coins[ind]);
            else return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = 1e9;
        int not_Take = 1e9;
        if(target >= coins[ind]) take = 1 + f(ind,coins,target - coins[ind],dp);
        not_Take = f(ind - 1,coins,target,dp);
        int ans = min(take,not_Take);
        return dp[ind][target] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1,-1));
        int ans = f(n-1,coins,amount,dp);
        if(ans == 1e9) return -1;
        else return ans;
    }
};