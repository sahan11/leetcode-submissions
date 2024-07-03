class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> arr(n, 0);
        arr[0] = 1;
        for(int i = 1;i<n;i++) {
            if(nums[i] ^ nums[i - 1]) {
                arr[i] = arr[i - 1] + 1;
            }
            else {
                arr[i] = 1;
            }
        }

        for(int i = 0;i<n;i++) {
            ans += arr[i];
        }
        return ans;
    }
};