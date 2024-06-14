class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cur = nums[0];
        int ans = 0;
        for(int i = 1;i<n;i++) {
            if(nums[i] <= cur){
                ans += cur - nums[i] + 1;
                cur = cur + 1;
            }
            else {
                cur = nums[i];
            }
        }
        return ans;
    }
};