class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> xpoint(points.size());
        int n = points.size();
        for(int i = 0;i<n;i++) {
            xpoint[i] = points[i][0];
        }
        int cnt = 0;
        int max_rect = -1;
        sort(xpoint.begin(), xpoint.end());
        for(int i = 0;i<n;i++) {
            cout<<xpoint[i]<<" ";
        }
        for(int i = 0;i<n;i++) {
            if(xpoint[i] > max_rect){
                cnt++;
                max_rect = xpoint[i] + w;
            }
        }
        return cnt;
    }
};