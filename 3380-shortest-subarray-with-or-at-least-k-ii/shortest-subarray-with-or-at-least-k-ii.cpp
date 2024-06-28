class Solution {
public:
    
    void performOrOperation(int &orVal, vector<int> &count, int x) {
        orVal |= x;
        for(int i = 0;i<32;i++) {
            count[i] += (x & (1 << i)) ? 1 : 0;
        }
    }

    void deleteOrOperation(int &orVal, vector<int> &count, int x) {
        for(int i = 0;i<32;i++) {
            count[i] += (x & (1 << i)) ? -1 : 0;
            if(count[i] == 0) orVal &= ~(1 << i);
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(32, 0);
        int l = 0;
        int u = 0;
        int ans = INT_MAX;
        int orVal = 0;
        while(u < n) {
            performOrOperation(orVal, count, nums[u]);
            cout<<orVal<<endl;
            if(orVal >= k) {
                while(l <= u && orVal >= k) {
                    deleteOrOperation(orVal, count, nums[l]);
                    ans = min(ans, u - l + 1); 
                    l++;
                }
            }
            u++;
        }
        return ans == INT_MAX ? -1 : ans;

        

        // return ans;
    }
};