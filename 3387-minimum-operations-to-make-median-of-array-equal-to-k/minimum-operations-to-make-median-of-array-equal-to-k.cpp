class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto it = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
        int n = nums.size();
        int st_ind = n / 2;
        int end_ind = it;
        long long sum = 0;
        if(st_ind > end_ind) {
            for(int i = end_ind;i<=st_ind;i++) {
                sum += nums[i] - k;
            }
        }
        else if(st_ind < end_ind) {
            for(int i = st_ind;i<=end_ind - 1;i++) {
                sum += k - nums[i];
            }
        }
        else {
            sum += max(nums[st_ind] - k, k - nums[st_ind]);
        }
        return sum;
    }
};