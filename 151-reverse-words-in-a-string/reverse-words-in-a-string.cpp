class Solution {
public:
    string reverseWords(string s) {
        string wd = "";
        string newstr = "";
        int i = 0;
        while(i < s.size()) {
            while(i < s.size() && s[i] == ' ') {
                i++;
            }
            while(i < s.size() && s[i] != ' '){
                wd += s[i];
                i++;
            }
            while(i < s.size() && s[i] == ' ') {
                i++;
            }
            newstr = wd + " " + newstr;
            wd = "";
            if(i == s.size()){
                break;
            }
            
        }
        // newstr = newstr.substr(0, newstr.size() - 1);

        newstr = newstr.substr(0, newstr.length() - 1);
        return newstr;
    }
};