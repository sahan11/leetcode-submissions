class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int u = n - 1;

        while(l < u){
            if(nums[l] + nums[u] < target){
                l++;
            }
            else if(nums[l] + nums[u] > target){
                u--;
            }
            else{
                return{l + 1, u + 1};
            }
        }
        return {-1, -1 };
    }
};