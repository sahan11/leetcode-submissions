class Solution {
public:
    string getSmallestString(string s, int k) {
        string new_str = "";
        for(int i = 0;i<s.size();i++) {
            if(min(s[i] - 'a', 'a' - s[i] + 26) <= k){
                new_str += 'a';
                k -= min(s[i] - 'a', 'a' - s[i] + 26);
            }
            else if(k > 0){
                char plus = (char)((s[i] - 'a' + k) % 26 + 'a');
                char minus = (char)(((s[i] - 'a' - k + 26) % 26) + 'a');
                new_str += (char)min(plus, minus);
                k = 0;
            }
            else if(k == 0) new_str += s[i];
        }
        return new_str;
    }
};