class Solution {
public:
    int minimumLength(string s) {
        int arr[26];
        for(int i = 0;i<s.size();i++) {
            arr[s[i] - 'a']++;
        }

        int ans = 0;
        for(int i = 0;i<26;i++) {
            ans += arr[i] == 0 ? 0 : (arr[i] & 1 ? 1 : 2);
        }
        return ans;
    }
};