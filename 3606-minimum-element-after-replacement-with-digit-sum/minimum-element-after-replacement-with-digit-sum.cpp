class Solution {
public:
    int calc(int n) {
        int sum = 0;
        while(n > 0) {
            int dg = n % 10;
            sum += dg;
            n = n / 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = 1e9;
        for(int i = 0;i<nums.size();i++) {
            mini = min(mini, calc(nums[i]));
        }
        return mini;
    }
};