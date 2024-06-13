class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        const int max_L = 1e5;
        int n = rewardValues.size();
        bitset<max_L> dp, mask;
        dp[0] = true;
        sort(rewardValues.begin(), rewardValues.end());
        int mask_pos = 0;
        for(int i = 0;i + 1 < rewardValues.size();++i) {
            if(mask_pos < rewardValues[i]){
                while(mask_pos < rewardValues[i]) {
                    mask[mask_pos++] = true;
                }

                dp |= (dp & mask) << rewardValues[i];
            }
        }

        int cnt = rewardValues[n - 1] - 1;
        cout<<cnt<<endl;
        while(!dp[cnt]){
            --cnt;
        }

        return rewardValues[n - 1] + cnt;
        

    }
};