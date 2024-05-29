class Solution {
public:
    
    int countPath(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;

        if(row == m - 1 && col == n - 1) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int right = 0;
        int down = 0;
        if(row + 1 < m && obstacleGrid[row + 1][col] != 1) right = countPath(row + 1, col, obstacleGrid, dp);
        if(col + 1 < n && obstacleGrid[row][col + 1] != 1) down = countPath(row, col + 1, obstacleGrid, dp);
        return dp[row][col] = (right + down);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPath(0, 0, obstacleGrid, dp);
    }
};