class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptBottles = 0;
        while(true) {
            ans += numBottles;
            emptBottles += numBottles;
            numBottles = emptBottles / numExchange;
            emptBottles = emptBottles % numExchange;
            if(numBottles == 0) break;
            
        }
        return ans;
    }
};