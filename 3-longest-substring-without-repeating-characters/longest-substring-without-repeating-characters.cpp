class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> charSet;
        int l = 0;
        int u = 0;
        int maxLength = 0;
        
        while(u < n) {
            if(charSet.count(s[u]) == 0) {
                charSet.insert(s[u]);
                maxLength = max(maxLength, u - l + 1);

            }
            else {
                while(charSet.count(s[u])) {
                    charSet.erase(s[l]);
                    l++;
                }
                charSet.insert(s[u]);
                
            }
            u++;
        }

        return maxLength;
    }
};