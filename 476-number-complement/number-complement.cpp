class Solution {
public:
    int findComplement(int num) {
        return (pow(2, (int)log2(num) + 1) - num - 1);
    }
};