class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0;i<32;i++) {
            if(1<<i & c){
                if(!(1<<i & a) && !(1<<i & b)) cnt++;
            }
            else {
                if(1<<i & a) cnt++;
                if(1<<i & b) cnt++;
            }
        }
        return cnt;
    }
};