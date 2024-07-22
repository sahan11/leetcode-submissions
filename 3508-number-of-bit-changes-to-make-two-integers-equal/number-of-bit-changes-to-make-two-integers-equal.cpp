class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        for(int i = 0;i<32;i++) {
            if(((1 << i) & n) == ((1 << i) & k)) continue;
            else {
                if((1 << i) & n){
                    cnt++;
                }
                else return -1;
            }
        }
        return cnt;
    }
};