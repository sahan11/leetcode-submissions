class Solution {
public:
    int passThePillow(int n, int time) {
        int loop = (time) / (n - 1);
        int pos = (time) % (n - 1);
        if(loop & 1) {
            return n - pos;
        }
        else {
            return pos + 1;
        }
    }
};