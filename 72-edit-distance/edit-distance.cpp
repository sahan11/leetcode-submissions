class Solution {
public:
    // int countSteps(int ind1, int ind2, string word1, string word2, vector<vector<int>> &dp) {
    //     if(ind1 == -1) return ind2 + 1;
    //     if(ind2 == -1) return ind1 + 1;

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //     int one = countSteps(ind1 - 1, ind2, word1, word2, dp) + 1;
    //     int two = countSteps(ind1, ind2 - 1, word1, word2, dp) + 1;
    //     int three = countSteps(ind1 - 1, ind2 - 1, word1, word2, dp) + (word1[ind1] == word2[ind2] ? 0 : 1);

    //     return dp[ind1][ind2] = min({one, two, three});
    // }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // return countSteps(m - 1, n - 1, word1, word2, dp);
        for(int ind1 = 0;ind1<=m;ind1++) {
            for(int ind2 = 0;ind2<=n;ind2++) {
                if(ind1 == 0) dp[ind1][ind2] = ind2;
                else if(ind2 == 0) dp[ind1][ind2] = ind1;

                else {
                    int one = dp[ind1 - 1][ind2] + 1;
                    int two = dp[ind1][ind2 - 1] + 1;
                    int three = dp[ind1 - 1][ind2 - 1] + (word1[ind1 - 1] == word2[ind2 - 1] ? 0 : 1);

                    dp[ind1][ind2] = min({one, two, three});
                }


            }
        }

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                cout<<dp[i][j]<<" ";
            }cout<<'\n';
        }

        return dp[m][n];


    }
};