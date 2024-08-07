class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for(int i = 0;i<word.size();i++) {
            cnt[word[i] - 'a']++;
        }
        sort(cnt.begin(), cnt.end());
        int it = 25;
        int multiplier = 8;
        int ans = 0;
        while(it >= 0 && cnt[it] > 0) {
            ans += ((multiplier++) / 8) * cnt[it];
            it--;
        }
        return ans;
    }
};