class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curFlip = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            if((nums[i] + curFlip) % 2 == 0) {
                curFlip++;
                
            }
        }
        return curFlip;
    }
};