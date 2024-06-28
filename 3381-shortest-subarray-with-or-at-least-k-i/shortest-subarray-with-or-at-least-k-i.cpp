class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<n;i++) {
            for(int j = i;j<n;j++) {
                int orval = 0;
                for(int l = i;l<=j;l++) {
                    orval |= nums[l];
                    if(orval >= k) break;
                }
                if(orval >= k) ans = min(ans, j - i + 1);
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};