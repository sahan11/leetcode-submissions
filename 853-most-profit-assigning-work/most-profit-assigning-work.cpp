class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> arr;
        int n = profit.size();

        for(int i = 0;i<n;i++) {
            arr.push_back({difficulty[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        vector<int> maxi(n, -1);
        maxi[0] = arr[0].second;
        int m = arr[0].second;
        for(int i = 1;i<n;i++) {
            if(m < arr[i].second){
                m = arr[i].second;
            }
            maxi[i] = m;
        }
        for(int i = 0;i<n;i++) {
            cout<<arr[i].first<<" "<<arr[i].second<<" "<<maxi[i]<<endl;
        }
        // return 1;


        for(int i = 0;i<n;i++) {
            difficulty[i] = arr[i].first;
            profit[i] = arr[i].second;
        }

        m = worker.size();
        int ans = 0;
        for(int i = 0;i<m;i++) {
            int ind = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin() - 1;
            cout<<ind<<endl;
        
            if(ind >= 0) ans += maxi[ind]; 
        }
        return ans;
    }
};