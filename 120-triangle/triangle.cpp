class Solution {
public:
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        
        vector<int> cur(rows,0), prev(rows,0);
        
        for(int i = rows-1;i>=0;i--){
            for(int j = i;j>=0;j--){
                if(i == rows-1){
                    cur[j] = triangle[i][j];
                    continue;
                }
                int down = triangle[i][j] + prev[j];
                int right = triangle[i][j] + prev[j+1];
                
                cur[j] = min(down,right);

            }
            prev = cur;
        }
        return prev[0];
    }
};