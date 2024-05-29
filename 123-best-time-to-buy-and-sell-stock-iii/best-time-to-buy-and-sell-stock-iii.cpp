class Solution {
public:
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<2;buy++){
                for(int cap = 1;cap<3;cap++){
                    if(buy){
                        dp[ind][1][cap] = max(dp[ind+1][0][cap] - prices[ind], dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][0][cap] = max(dp[ind+1][1][cap-1] + prices[ind], dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};