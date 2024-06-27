class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minGrid(m, vector<int>(n, INT_MAX));
        minGrid[0][0] = grid[0][0];
        int res = INT_MIN;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(i - 1 >= 0 && j - 1 >= 0) minGrid[i][j] = min({grid[i - 1][j], minGrid[i - 1][j], grid[i][j - 1], minGrid[i][j - 1]});
                else if(i - 1 >= 0) minGrid[i][j] = min(grid[i - 1][j], minGrid[i - 1][j]);
                else if(j - 1 >= 0) minGrid[i][j] = min(grid[i][j - 1], minGrid[i][j - 1]);
                if(!(i == 0 && j == 0))res = max(grid[i][j] - minGrid[i][j], res);
            }
        }
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                cout<<minGrid[i][j]<<" ";
            }cout<<endl;
        }

        return res;

        

    }
};