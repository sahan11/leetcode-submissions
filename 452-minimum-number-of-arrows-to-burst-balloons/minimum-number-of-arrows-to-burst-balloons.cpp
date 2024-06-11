class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        for(int i = 0;i<points.size();i++) {
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        int n = points.size();
        int start_ind;
        int end_ind;
        vector<vector<int>> ans;
        ans.push_back(points[0]);
        start_ind = points[0][0];
        end_ind = points[0][1];

        for(int i = 1;i<n;i++) {
            if(end_ind < points[i][0]){
                ans.push_back(points[i]);
                start_ind = points[i][0];
                end_ind = points[i][1];
            }
            else {
                ans.pop_back();
                ans.push_back({max(start_ind, points[i][0]), min(end_ind, points[i][1])});
                start_ind = max(start_ind, points[i][0]);
                end_ind = min(end_ind, points[i][1]);
            }
        }

        return ans.size();
    }
};