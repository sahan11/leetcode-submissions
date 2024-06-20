class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> cnt(dominoes.size(), 0);
        vector<int> ans(dominoes.size(), 0);
        queue<vector<int>> q;
        for(int i = 0;i<dominoes.size();i++) {
            if(dominoes[i] == 'L') {
                q.push({-1, i, 0});
                ans[i] = -1;
            }
            else if(dominoes[i] == 'R'){
                q.push({1, i, 0});
                ans[i] = 1;
            }
            
        }
        while(!q.empty()) {
            int dir = q.front()[0];
            int ind = q.front()[1];
            int dis = q.front()[2];
            q.pop();

            if(dir == -1) {
                if(ind - 1 >= 0 && ans[ind - 1] == 0) {
                    ans[ind - 1] = -1;
                    cnt[ind - 1] = dis + 1;
                    q.push({-1, ind - 1, dis + 1});
                }
                else if(ind - 1 >= 0 && ans[ind - 1] == 1) {
                    if(cnt[ind - 1] == dis + 1) {
                        ans[ind - 1] = 0;
                        
                    } 
                }
            }
            else if(dir == 1) {
                if(ind + 1 < n && ans[ind + 1] == 0) {
                    ans[ind + 1] = 1;
                    cnt[ind + 1] = dis + 1;
                    q.push({1, ind + 1, dis + 1});
                }
                else if(ind + 1 < n && ans[ind + 1] == -1) {
                    if(cnt[ind + 1] == dis + 1) {
                        ans[ind - 1] = 0;
                        
                    } 
                }
                
            }
        }

        string new_str = "";
        for(int i = 0;i<n;i++) {
            if(ans[i] == 1) {
                new_str += 'R';
            }
            else if (ans[i] == 0) {
                new_str += '.';
            }
            else new_str += 'L';
        }
        return new_str;
    }
};