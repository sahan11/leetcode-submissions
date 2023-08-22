class Solution {
public:
    int f(int x, vector<int> &dp){
        if(x < 0) return 0;
        if(x == 0) return 1;
        if(dp[x] != -1) return dp[x];
        return dp[x] = f(x - 1, dp) + f(x - 2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
            dp[0] = 1;
            dp[1] = 1;

        for(int x = 2;x<=n;x++){
            
            
            dp[x] = dp[x - 1] + dp[x - 2];
        }
        return dp[n];
    }
};