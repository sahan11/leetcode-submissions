class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        if(c == 1) return true;
        for(int i = 1;i<=sqrt(c);i++) {
            int check = c - (i * i);
            if(((int)sqrt(check) * (int)sqrt(check)) == check){
                cout<<check<<endl;
                return true;  
            } 
        }
        return false;
    }
};