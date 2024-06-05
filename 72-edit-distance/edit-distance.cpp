class Solution {
public:
    int countSteps(int ind1, int ind2, string word1, string word2, vector<vector<int>> &dp) {
        if(ind1 == -1) return ind2 + 1;
        if(ind2 == -1) return ind1 + 1;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int one = countSteps(ind1 - 1, ind2, word1, word2, dp) + 1;
        int two = countSteps(ind1, ind2 - 1, word1, word2, dp) + 1;
        int three = countSteps(ind1 - 1, ind2 - 1, word1, word2, dp) + (word1[ind1] == word2[ind2] ? 0 : 1);

        return dp[ind1][ind2] = min({one, two, three});
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, - 1));
        return countSteps(m - 1, n - 1, word1, word2, dp);
    }
};