class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int k = 0;
        for(int i = 0;i<n;i++){
            arr.push_back(nums[i]);
            while(i + 1 < n && nums[i] == nums[i+1]){
                i++;
            }
            k++;
        }
        nums = arr;
        return k;
    }
};