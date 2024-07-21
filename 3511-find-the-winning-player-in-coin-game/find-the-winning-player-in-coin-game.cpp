class Solution {
public:
    string losingPlayer(int x, int y) {
        int a = x;
        int b = y / 4;

        if(min(a, b) & 1) return "Alice";
        else return "Bob";
    }
};