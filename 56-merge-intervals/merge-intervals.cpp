class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> arr;
        sort(intervals.begin(),intervals.end(),compare);
        for(int i = 0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i < n-1 && end >= intervals[i + 1][0]){
                i++;
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
            }
            arr.push_back({start,end});
            


        }
        return arr;
    }
};