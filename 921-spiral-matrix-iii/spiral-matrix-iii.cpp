class Solution {
public:
    bool isValid(int i, int j, int rows, int cols) {
        return (i >= 0 && i < rows && j >= 0 && j < cols);
    }
    
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int i = rStart;
        int j = cStart;
        int step = 1;
        int cnt = 1;
        int mult = 1;
        ans.push_back({rStart, cStart});
        while(cnt < rows * cols) {

            for(int b = 0;b < step;b++) {
                j = j + mult;
                if(isValid(i, j, rows, cols)){
                    ans.push_back({i, j});
                    cnt++;
                }
            }
            for(int a = 0;a < step;a++) {
                // if(a >= rows) break;
                i = i + mult;
                if(isValid(i, j, rows, cols)) {
                    ans.push_back({i, j});
                    cnt++;
                }
            }
            step++;
            mult = mult == 1 ? -1 : 1;
        }

        return ans;
        
    }
};