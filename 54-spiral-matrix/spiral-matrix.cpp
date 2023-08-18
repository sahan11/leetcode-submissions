class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int upBound = -1;
        int leftBound = -1;
        int rightBound = n;
        int bottomBound = m;
        vector<int> ans;
        while(upBound < bottomBound && leftBound < rightBound){
            if(upBound < bottomBound - 1){
                for(int i = leftBound + 1;i<rightBound;i++){
                    ans.push_back(matrix[upBound + 1][i]);
                }
            }
            
            upBound++;
            if(leftBound < rightBound - 1){
                for(int i = upBound + 1;i<bottomBound;i++){
                    ans.push_back(matrix[i][rightBound - 1]);
                }
            }
            
            rightBound--;
            for(int i = 0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }cout<<endl;
            if(upBound < bottomBound - 1){
                for(int i = rightBound - 1;i>leftBound;i--){
                    ans.push_back(matrix[bottomBound - 1][i]);
                }
            }
            
            cout<<"Hi"<<" ";
            bottomBound--;
            if(leftBound < rightBound - 1){
                for(int i = bottomBound - 1;i > upBound;i--){
                    ans.push_back(matrix[i][leftBound + 1]);
                }
            }
            
            leftBound++;
        }
        return ans;
    }
};