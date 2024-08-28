class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
    int dfs(int row, int col, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        vector<int> drow = {1, 0, -1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int ans = 1;

        for(int i = 0;i<4;i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(isValid(nrow, ncol, vis.size(), vis[0].size()) && !vis[nrow][ncol] && grid2[nrow][ncol]) {
                if(!grid1[nrow][ncol]) ans = 0; 
                ans = ans & dfs(nrow, ncol, grid1, grid2, vis);
            }
            
        }
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid2[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(!vis[i][j] && grid2[i][j] == 1 && grid1[i][j] == 1) {
                    int val = dfs(i, j, grid1, grid2, vis);
                    if(val) cout<<i<<" "<<j<<'\n';
                    ans = ans + val;
                }
            }
        }
        return ans;
    }
};