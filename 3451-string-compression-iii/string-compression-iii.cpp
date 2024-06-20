class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string new_str = "";
        int curCnt = 1;
        for(int i = 0;i<n;i++) {
            while(curCnt < 9 && i + 1 < n && word[i + 1] == word[i]){
                curCnt++;
                i++;
            }
            new_str += to_string(curCnt) + word[i];
            curCnt = 1;
        }
        return new_str;
    }
};