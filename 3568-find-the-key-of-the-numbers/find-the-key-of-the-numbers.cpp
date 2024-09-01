class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;
        int cnt = 0;
        while(num1 > 0 || num2 > 0 || num3 > 0) {
            int dg1 = num1 % 10;
            int dg2 = num2 % 10;
            int dg3 = num3 % 10;
            key = min({dg1, dg2, dg3}) * pow(10, cnt++) + key;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return key;
    }
};