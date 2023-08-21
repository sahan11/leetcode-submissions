class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> arr = citations;
        sort(arr.begin(), arr.end());
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            ans = max(ans, min(arr[i], n - i));
        }
        return ans;
    }
};