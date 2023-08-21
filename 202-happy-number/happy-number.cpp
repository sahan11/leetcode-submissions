class Solution {
public:
    bool f(int x){
        if(x < 10){
            return (x == 1 || x==7) ;
        }
        int sum = 0;
        while(x > 0){
            int dg = x % 10;
            x /= 10;
            sum += dg * dg;
        }
        return f(sum);
    }
    bool isHappy(int n) {
        return f(n);
    }
};