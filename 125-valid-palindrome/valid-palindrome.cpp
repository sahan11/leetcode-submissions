class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int u = s.size() - 1;

        while(l < u){
            if(toupper(s[l]) == toupper(s[u])){
                l++;
                u--;
            }
            else if(!(('a' <= s[l] && s[l] <= 'z') || ('A' <= s[l] && s[l] <= 'Z') || ('0' <= s[l] && s[l] <= '9'))){
                l++;
            }
            else if(!(('a' <= s[u] && s[u] <= 'z') || ('A' <= s[u] && s[u] <= 'Z') || ('0' <= s[u] && s[u] <= '9'))){
                u--;
            }
            else return false;
        }
        return true;
    }
};