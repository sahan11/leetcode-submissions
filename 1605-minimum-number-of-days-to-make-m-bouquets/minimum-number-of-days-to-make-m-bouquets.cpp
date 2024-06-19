class Solution {
public:
    bool check(vector<int> &arr, int x, int k, int m) {
        int curcnt = 0;
        int cnt = 0;
        cout<<"k = "<<k;
        for(int i = 0;i<arr.size();i++) {
            if(arr[i] <= x) {
                curcnt++;
            }
            else {
                curcnt = 0;
            }
            if(curcnt == k) {
                cnt++;
                curcnt = 0;
            }
            if(cnt == m) return true;

        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL * m * k > 1LL * n) return -1;

        int u = (*max_element(bloomDay.begin(), bloomDay.end())) + 1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;
        while(l < u) {
            int mid = (l + u) / 2;
            cout<<mid<<endl;
            if(check(bloomDay, mid, k, m)){
                ans = mid;
                u = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};