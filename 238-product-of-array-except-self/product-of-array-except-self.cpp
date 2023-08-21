class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n);
        vector<int> suSum(n);
        int a = 1;
        int b = 1;
        for(int i = 0;i<n;i++){
            preSum[i] = a * nums[i];
            a *= nums[i];
            suSum[n - i - 1] = b * nums[n - i - 1];
            b *= nums[n - i - 1];
        }
        for(int i = 0;i<n;i++) cout<<preSum[i]<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++){
            cout<<suSum[i]<<" ";
        }
        cout<<endl;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(i == 0) ans.push_back(suSum[1]);
            else if(i == n - 1) ans.push_back(preSum[n - 2]);
            else ans.push_back(preSum[i - 1] * suSum[i + 1]);
        }
        return ans;
    }
};