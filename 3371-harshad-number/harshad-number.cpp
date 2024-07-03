class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int cp = x;
        int sum = 0;
        while(cp > 0) {
            int dg = cp % 10;
            sum += dg;
            cp /= 10;
        }

        if(x % sum == 0) return sum;
        else return -1;
    }
};