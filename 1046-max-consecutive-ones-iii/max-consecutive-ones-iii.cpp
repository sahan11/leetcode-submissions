class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int zero_count = 0;
        int ans = -1;
        while(r < n) {
            if(nums[r] == 0) {
                zero_count++;
            }
            if(zero_count > k) {
                if(nums[l] == 0) zero_count--;
                l = l + 1;
            }

            if(zero_count <= k) {
                ans = max(ans, r - l + 1);
            }

            ans = max(ans, r - l + 1);
            r = r + 1;
        }

        return ans;
    }
};