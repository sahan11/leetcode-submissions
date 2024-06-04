class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int minimum = nums[0];
        int maximum = nums[n - 1];
        vector<int> mini(nums.size());
        vector<int> maxi(nums.size());

        for(int i = 0;i<n;i++) {
            mini[i] = min(nums[i], minimum);
            minimum = min(nums[i], minimum);
            
        }
        for(int i = n - 1;i>=0;i--) {
            maxi[i] = max(nums[i], maximum);
            maximum = max(nums[i], maximum);
        }

        for(int i = 0 ;i<n;i++) {
            if(mini[i] < nums[i] && nums[i] < maxi[i]) return true;
        }

        return false;
    }
};