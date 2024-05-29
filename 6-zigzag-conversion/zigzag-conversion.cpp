class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> arr(numRows);
        int i = 0;
        int toggle = 1;
        int ind = 0;
        if(numRows == 1) return s;
        while(i < s.size()) {
            arr[ind] += s[i];
            ind += toggle;
            if(ind == numRows - 1) toggle = -1;
            if(ind == 0) toggle = 1;
            i++;

        }

        string newstr = "";
        for(int i = 0;i<numRows;i++) {
            newstr += arr[i];
        }

        return newstr;
        
        
    }
};