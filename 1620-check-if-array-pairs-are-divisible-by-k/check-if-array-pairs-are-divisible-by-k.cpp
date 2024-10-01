class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        if(n & 1) return false;
        map<int, int> mp;
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if(arr[i] < 0) arr[i] = (arr[i] % k) + k;
            if(mp[(k - (arr[i] % k)) % k] > 0) {
                mp[(k - (arr[i] % k)) % k]--;
                cnt++;
            }
            else {
                mp[arr[i] % k]++;
            }
        }

        if(cnt == (n / 2)) return true;
        else return false;
    }
};