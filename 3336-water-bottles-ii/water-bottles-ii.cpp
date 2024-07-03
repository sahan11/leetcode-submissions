class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = 0;
        int emptBottles = 0;
        fullBottles = numBottles;

        int ans = 0;
        while(fullBottles > 0 || emptBottles >= numExchange) {
            while(emptBottles >= numExchange) {
                fullBottles += 1;
                emptBottles -= numExchange;
                numExchange++;
            }

            ans += fullBottles;
            emptBottles += fullBottles;
            fullBottles = 0;
        }

        return ans;
    }
};