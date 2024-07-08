class Solution {
public:
    int findTheWinner(int n, int k) {
        int ind = 0;int cnt = n;
        k = (k - 1) % n;
        vector<int> vis(n, 0);
        while(cnt > 1) {
            for(int i = 1;i<=k;i++) {
                ind = (ind + 1) % n;
                while(vis[ind]) ind = (ind + 1) % n;
            }
            vis[ind] = 1;
            while(vis[ind]) ind = (ind + 1) % n;
            cnt--;
        }
        return (ind % n) + 1;
    }
};