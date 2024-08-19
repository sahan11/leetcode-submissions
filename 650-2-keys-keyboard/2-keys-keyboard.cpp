class Solution {
public:
    int minSteps(int n) {
        int curSize = 1;
        int cur = 1;
        int cnt = 0;
        while(curSize < n) {
            if((n - curSize) % curSize == 0) {
                cur = curSize;
                curSize += cur;
                cnt += 2;
            }
            else {
                curSize += cur;
                cnt++;
            }
            
        }
        return cnt;
    }
};