class Solution {
public:
    int check(vector<int> &nums, int x) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int cnt = 0;
        while(i < n) {
            while(j < n && nums[i] + x >= nums[j]) j++;
            cnt += j - i - 1;
            i++;
        }
        return cnt;
    }
     
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int u = nums[n - 1];
        while(l < u) {
            int mid = l + (u - l) / 2;
            int cnt = check(nums, mid);
            if(cnt < k) {
                l = mid + 1;
            }
            else {
                u = mid;
            }
        }
        return l;
    }
};