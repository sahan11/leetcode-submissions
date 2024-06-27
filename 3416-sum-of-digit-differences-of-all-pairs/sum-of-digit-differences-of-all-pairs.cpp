class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        while(nums[0] > 0){
            vector<int> cnt(10, 0);
            int cnt_dg = 0;
            int n = nums.size();
            for(int i = 0;i<nums.size();i++) {
                int dg = nums[i] % 10;
                nums[i] /= 10;
                if(cnt[dg] == 0) cnt_dg++;
                cnt[dg]++;
            }
            // long long temp_ans = 1;
            for(int i = 0;i<10;i++) {
                ans += 1LL * cnt[i] * (n - cnt[i]);
                cout<<cnt[i]<<endl;
                
            }

            // cout<<"temp_ans = "<<temp_ans<<endl;
            
            
        }
        return ans / 2;
        
    }
};