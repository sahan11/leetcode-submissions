class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> a(s.size() + 1, 0);
        vector<int> b(s.size() + 1, 0);
        int a_count = 0;
        int b_count = 0;
        for(int i = 1;i<=s.size();i++) {
            if(s[i - 1] == 'a') {
                a_count++;
                // a[i] = a_count;
            }
            if(s[i - 1] == 'b') {
                b_count++;
                // b[i] = b_count;
            }
            a[i] = a_count;
            b[i] = b_count;
        }

        
        int res = INT_MAX;
        int n = a.size();
        // for(int i = 0;i<n;i++) {
        //     cout<<a[i]<<" ";
        // }cout<<endl;
        // for(int i = 0;i<n;i++) {
        //     cout<<b[i]<<" ";
        // }cout<<endl;
        for(int i = 0;i<n;i++) {
            if(i == 0) {
                res = min(res, a[n - 1 - i]);
            }
            else if(i == n - 1) {
                res = min(res, b[i]);
            }
            else {
                res = min(res, b[i] + a[n - 1] - a[i]);
            }
        }

        return res;
    }
};