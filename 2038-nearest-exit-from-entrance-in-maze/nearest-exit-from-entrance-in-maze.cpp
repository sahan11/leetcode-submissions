class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, pair<int, int>>> q;
        int m = maze.size();
        int n = maze[0].size();
        q.push({0, {entrance[0], entrance[1]}});
        vector<vector<int>> vis(m, vector<int>(n, 0));
        while(!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(vis[row][col]) continue;
            vis[row][col] = 1;


            vector<int> drow = {1, 0, -1, 0};
            vector<int> dcol = {0, 1, 0, -1};

            for(int i = 0;i<4;i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && maze[nrow][ncol] != '+' && !vis[nrow][ncol]) {
                        cout<<nrow<<" "<<ncol<<endl;
                    if(nrow == m - 1 || ncol == n - 1 || nrow == 0 || ncol == 0) {
                        cout<<nrow<<" "<<ncol<<endl;
                        return dist + 1;
                    }
                    q.push({dist + 1, {nrow, ncol}});

                }
            }
        }
        return -1;
    }
};