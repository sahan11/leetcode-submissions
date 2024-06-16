class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp;
        int n = hours.size();
        long long cnt = 0;
        for(int i = 0;i<n;i++) {
            if(mp.find((24 - (hours[i] % 24)) % 24) != mp.end()) {
                cnt += mp[(24 - (hours[i] % 24)) % 24];
            }
            mp[hours[i] % 24]++;
        }
        return cnt;
    }
};