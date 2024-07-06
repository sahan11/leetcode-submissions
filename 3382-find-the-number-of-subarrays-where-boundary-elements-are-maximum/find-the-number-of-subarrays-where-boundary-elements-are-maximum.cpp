class Solution {
public:
    vector<int> popCount(stack<int> &st, int val) {
        map<int, int> mp;
        while(!st.empty() && st.top() < val) {
            mp[st.top()]++;
            st.pop();
        }
        st.push(val);
        vector<int> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }

    long long calcCount(vector<int> arr) {
        long long sum = 0;
        
        for(int i = 0;i<arr.size();i++) {
            sum += arr[i] & 1 ? 1LL * ((arr[i] - 1) / 2) * arr[i] : 1LL * (arr[i] / 2) * (arr[i] - 1);
        }

        return sum;
    }
    
    long long numberOfSubarrays(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        long long sum = nums.size();
        for(int i = 0;i<n;i++) {
            if(!st.empty() && st.top() < nums[i]) {
                sum += calcCount(popCount(st, nums[i]));
            }
            else  {
                st.push(nums[i]);
            }
        }

        sum += calcCount(popCount(st, 1e9 + 1));
        return sum;
    }
};