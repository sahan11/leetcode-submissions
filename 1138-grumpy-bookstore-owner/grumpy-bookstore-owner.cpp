class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxSum = 0;
        int l = 0;
        int u = minutes - 1;
        int ans = 0;
        
        for(int i = l;i<=u;i++) {
            if(grumpy[i] == 1) maxSum += customers[i];
        }
        ans = max(ans, maxSum);
            
        while(u < n - 1) {
            u++;
            if(grumpy[u] == 1) maxSum += customers[u];
            if(grumpy[l] == 1) maxSum -= customers[l];
            l++;
            cout<<l<<" "<<u<<" "<<maxSum<<endl;
            ans = max(ans, maxSum);
        }

        for(int i = 0;i<n;i++) {
            if(grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        return ans;
    }
};