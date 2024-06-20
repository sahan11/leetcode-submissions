class Solution {
public:
    bool check(vector<int> &arr, int m, int x) {
        int curCnt = x;
        for(int i = 0;i<arr.size();i++) {
            if(i != 0) curCnt += arr[i] - arr[i - 1];
            if(curCnt >= x) {
                m--;
                if(m == 0) return true;
                curCnt = 0;
            }
            
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        // if(m == 3) return 3;
        // if(m == 2) return 999999999;
        sort(position.begin(), position.end());
        
        int l = 1;
        int u = *max_element(position.begin(), position.end()) + 1;
        int ans = 0;
        while(l < u) {
            int mid = (l + u) / 2;
            if(check(position, m, mid)) {
                if(ans == mid) break;
                ans = mid;
                l = mid;
        // cout<<l<<" "<<u<<" "<<mid<<endl;
            }
            else {
                u = mid;
        cout<<l<<" "<<u<<" "<<mid<<endl;
            }
        }
        return ans;
    }
};