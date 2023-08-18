class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowmax(n);
        vector<int> colmax(n);
        for(int i = 0;i<n;i++){
            int maxir = -1e9;
            int maxic = -1e9;
            for(int j = 0;j<n;j++){
                maxir = max(grid[i][j], maxir);
                maxic = max(grid[j][i], maxic);
            }
            rowmax[i] = maxir;
            colmax[i] = maxic;
        }

        for(int i = 0;i<n;i++){
            cout<<rowmax[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i<n;i++){
            cout<<colmax[i]<<" ";
        }
        cout<<endl;

        int sum = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum += max((min(rowmax[i], colmax[j]) - grid[i][j]), 0);
            }
        }

        return sum;
        
    }
};