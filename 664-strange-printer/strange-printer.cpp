class Solution {
public:
    int f(int l, int u, string s, vector<vector<int>> &dp) {
        if(l == u) return 1;
        if(dp[l][u] != -1) return dp[l][u];
        int mini = INT_MAX;
        for(int mid = l;mid<u;mid++) {
            mini = min(mini, f(l, mid, s, dp) + f(mid + 1, u, s, dp) - (s[l] == s[u]));
        }
        return dp[l][u] = mini;
    }
    
    int strangePrinter(string str) {
        string s = "";
        for(int i = 0;i<str.size();i++) {
            s = s + str[i];
            while(i < str.size() - 1 && str[i] == str[i + 1]){
                i++;
            }
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, s.size() - 1, s, dp);
    }
};