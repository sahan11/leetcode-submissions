class Solution {
public:
    int minDifference(vector<int>& nums) {
        // map<int, int> mp;
        int mini = INT_MAX;
        

        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 4) return 0;

        int l = 0;
        int u = n - 4;
        // int mini = INT_MAX;
        for(int i = 0;i<=3;i++) {
            mini = min(nums[u + i] - nums[i], mini);
        }
        return mini;
        


        




    }
};