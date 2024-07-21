class Solution {
public:
    int f(int startRow, int endRow, int startCol, int endCol, vector<int> &hCut, vector<int> &vCut, int dp[21][21][21][21]) {
        if(endRow - startRow == 1 && endCol - startCol == 1) return 0;
        if(dp[startRow][endRow][startCol][endCol] != -1) return dp[startRow][endRow][startCol][endCol];
        int mini = 1e9;

        for(int i = startRow;i<endRow - 1;i++) {
            mini = min(mini, hCut[i] + f(i + 1, endRow, startCol, endCol, hCut, vCut, dp) + f(startRow, i + 1, startCol, endCol, hCut, vCut, dp));
        }

        for(int i = startCol;i<endCol - 1;i++) {
            mini = min(mini, vCut[i] + f(startRow, endRow, i + 1, endCol, hCut, vCut, dp) + f(startRow, endRow, startCol, i + 1, hCut, vCut, dp));
        }

        return dp[startRow][endRow][startCol][endCol] = mini;
    }
    
    int minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        int dp[21][21][21][21];
        memset(dp, -1, sizeof(dp));
        return f(0, m, 0, n, hCut, vCut, dp);
    }
};