class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int sum = 0;
        int m = grid.size();
        int n = grid[0].size();

        sum += m * (1 << n - 1);

        for(int j = 1;j<n;j++){
            int count1 = 0;
            int count0 = 0;
            for(int i = 0;i<m;i++){
                if(!(grid[i][0] ^ grid[i][j])) count0++;
                else count1++;
                    
               
            }
            sum += max(count0, count1) * (1 << n - j - 1);
        }
        return sum;
    }
};