class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        long long curSum = 0;
        int cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] < curSum + 2) {
                curSum += nums[i];
            }
            else {
                curSum += curSum + 1;
                cnt++;
                i--;
            }
            if(curSum >= n) return cnt;


        }
        while(curSum < n) {
            curSum += curSum + 1;
            cnt++;
        }
        return cnt;
    }
};