class Solution {
public:
    int f(int ind, int buy, vector<int> &val,vector<vector<int>> &dp){
        int n = val.size();
        if(ind == n){
            return 0;
        }
        int take;
        int not_Take;
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        if(buy){
            not_Take = f(ind+1,1,val,dp);
            take = f(ind + 1,0,val,dp) - val[ind];
            return dp[ind][1] = max(take, not_Take);
        }
        else{
            not_Take = f(ind + 1,0,val,dp);
            take = f(ind + 1,1,val,dp) + val[ind];
            return dp[ind][0] = max(take, not_Take);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int ahead_0 = 0;;
        int ahead_1 = 0;;
        int cur_1 = 0;
        int cur_0 = 0;
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<2;buy++){
                if(buy){
                    
                    cur_1 = max(ahead_0 - prices[ind], ahead_1);
                }
                else{
                    
                    cur_0 = max(ahead_1 + prices[ind], ahead_0);
                }
            }
            ahead_1 = cur_1;
            ahead_0 = cur_0;
        }
        return ahead_1;
    }
};