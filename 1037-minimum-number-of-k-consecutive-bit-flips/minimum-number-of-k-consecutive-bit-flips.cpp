class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> xorArr(n, 0);

        int flag = 0;
        int cnt = 0;
        int curFlips = 0;
        for(int i = 0;i<n;i++) {
            if(xorArr[i] == 1) curFlips--;
            if((nums[i] + curFlips) % 2 == 0) {
                cnt++;
                xorArr[i] = 1;
                curFlips++;
                if(i + k < n) xorArr[i + k] = 1;
                if(i + k > n) return -1;

            } 
            // flag = flag ^ xorArr[i];
        }
        return cnt;
    }
};