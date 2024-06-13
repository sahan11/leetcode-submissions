class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int cur = skills[0];
        int cur_ind = 0;
        int streak = 0;
        for(int i = 1;i<skills.size();i++) {
            if(cur > skills[i]) {
                streak++;
            }
            else {
                streak = 1;
                cur = skills[i];
                cur_ind = i;
            }
            if(streak == k) return cur_ind;
        }
        return cur_ind;
    }
};