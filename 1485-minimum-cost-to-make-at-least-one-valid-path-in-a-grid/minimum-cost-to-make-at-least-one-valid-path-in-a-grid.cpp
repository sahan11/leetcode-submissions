class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m + 1, vector<int>(n + 1, 0));

        deque<vector<int>> dq;
        dq.push_back({0, 0, 0});
        vector<vector<int>> dist(m + 1, vector<int>(n + 1, 1e9));
        dist[0][0] = 0;
        while(!dq.empty()) {
            int cost = dq.front()[0];
            int row = dq.front()[1];
            int col = dq.front()[2];
            dq.pop_front();

            if(vis[row][col]) continue;
            else vis[row][col] = 1;

            vector<int> drow = {-2, 0, 0, 1, -1};
            vector<int> dcol = {-2, 1, -1, 0, 0};

            for(int i = 1;i<=4;i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(i == grid[row][col] && dist[nrow][ncol] > cost) {
                        dist[nrow][ncol] = cost;
                        dq.push_front({dist[nrow][ncol], nrow, ncol});
                    }
                    else if(i != grid[row][col] && dist[nrow][ncol] > cost + 1) {
                        dist[nrow][ncol] = cost + 1;
                        dq.push_back({dist[nrow][ncol], nrow, ncol});
                    }
                } 
                
            }
        }
        if(dist[m - 1][n - 1] == 1e9) return -1;
        else return dist[m - 1][n - 1];
    }
};