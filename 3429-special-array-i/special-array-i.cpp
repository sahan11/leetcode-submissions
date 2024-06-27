class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int cr = nums[0] % 2;
        int n = nums.size();
        for(int i = 1;i<n;i++) {
            if((nums[i] % 2) ^ cr == 0) return false;
            else {
                cr = nums[i] % 2;
            }
        }
        return true;
    }
};