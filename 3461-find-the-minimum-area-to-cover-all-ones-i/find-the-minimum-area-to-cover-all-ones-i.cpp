class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = 1e9;
        int maxX = -1;
        int minY = 1e9;
        int maxY = -1;
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    minX = min(i, minX);
                    maxX = max(i, maxX);
                    minY = min(j, minY);
                    maxY = max(j, maxY);
                }
            }
        }

        return ((maxY - minY + 1) * (maxX - minX + 1));
    }
};