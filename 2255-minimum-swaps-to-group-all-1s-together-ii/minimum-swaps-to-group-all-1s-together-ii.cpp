class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            if(nums[i] == 1) total++;
        }

        int last = total - 1;
        int first = 0;
        int count = 0;
        for(int i = first;i<=last;i++) {
            if(nums[i] == 0) count++;
        }
        int ans = INT_MAX;
        ans = min(ans, count);
        while(first < n - 1) {
            // last = (last + 1) % n;
            if(!nums[++last % n]) count++;
            if(!nums[first++]) count--;
            ans = min(ans, count);

            
        }
        return ans;
    }
};