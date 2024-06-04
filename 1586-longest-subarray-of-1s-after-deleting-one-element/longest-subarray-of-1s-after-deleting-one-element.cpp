class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxCount = -1;
        int n = nums.size();
        int curCount = 0;
        int prevCount = 0;
        for(int i = 0;i<n;i++) {
            if(nums[i] == 1) curCount++;
            else if(nums[i] == 0) {
                maxCount = max(maxCount, prevCount + curCount);
                prevCount = curCount;
                curCount = 0;
            }
        }

        if(maxCount == -1) return n - 1;
        maxCount = max(maxCount, prevCount + curCount);
        return maxCount;
    }
};