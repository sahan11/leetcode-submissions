class Solution {
public:
    long long maximumTotalSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long int sum = 0;
        int cur = 1e9 + 1;
        for(int i = arr.size() - 1;i>=0;i--) {
            cur = min(cur - 1, arr[i]);
            if(cur <= 0) return -1;
            sum += cur;
        }

        return sum;
    }
};