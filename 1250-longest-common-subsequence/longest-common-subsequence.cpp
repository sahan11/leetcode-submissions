class Solution {
public:
    int countSub(int ind1, int ind2, string text1, string text2, vector<vector<int>> &dp) {
        if(ind1 == -1) return 0;
        if(ind2 == -1) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] = countSub(ind1 - 1, ind2 - 1, text1, text2, dp) + 1;
        else {
            return dp[ind1][ind2] = max(countSub(ind1 - 1, ind2, text1, text2, dp), countSub(ind1, ind2 - 1, text1, text2, dp));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0;i<=m;i++) {
            for(int j = 0;j<=n;j++) {
                if(i > 0 && j > 0) {
                    if(text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        return dp[m][n];
        
    }
};