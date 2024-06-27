class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int cr = nums[0] % 2;
        int n = nums.size();
        vector<int> check(n, 0);
        for(int i = 1;i<n;i++) {
            if((nums[i] % 2) ^ cr == 0) {
                check[i] = 1;
            }
            else {
                cr = nums[i] % 2;
            }
        }
        for(int i = 1;i<n;i++) {
            check[i] += check[i - 1];
        }
        vector<bool> ans;
        for(auto it : queries) {
            int l = it[0];
            int r = it[1];

            if(check[r] - check[l] > 0) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};