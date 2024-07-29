class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for(int i = 1;i<rating.size() - 1;i++) {
            vector<int> less(2, 0);
            vector<int> more(2, 0);
            // int res = 0;
            for(int j = 0;j<rating.size();j++) {
                if(j == i) continue;
                if(rating[j] < rating[i]) {
                    less[j < i]++;
                }
                else if(rating[j] > rating[i]) {
                    more[j < i]++;
                }
            }
            res += less[0] * more[1] + less[1] * more[0];
        }
        return res;
    }
};