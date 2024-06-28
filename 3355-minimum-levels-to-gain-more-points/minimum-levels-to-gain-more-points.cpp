class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> prefSum(n, 0);
        prefSum[0] = possible[0] == 1 ? 1 : -1;
        for(int i = 1;i<n;i++) {
            if(possible[i] == 1) prefSum[i] = prefSum[i - 1] + 1;
            else prefSum[i] = prefSum[i - 1] - 1;
        }

        for(int i = 0;i<n - 1;i++) {
            if(prefSum[i] > prefSum[n - 1] - prefSum[i]) return (i + 1);
        }
        return -1;

    }
};