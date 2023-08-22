class Solution {
public:
    int f(int x, vector<int> &dp){
        if(x < 0) return 0;
        if(x == 0) return 1;
        if(dp[x] != -1) return dp[x];
        return dp[x] = f(x - 1, dp) + f(x - 2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};