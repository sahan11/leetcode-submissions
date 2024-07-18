class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i = 1;i<n;i++) {
            if((((s[i] - 0) & 1) == ((s[i - 1] - 0) & 1)) && (s[i] < s[i - 1])) {
                char temp = s[i];
                s[i] = s[i - 1];
                s[i - 1] = temp;
                break;
            }

        }
        return s;
    }
};