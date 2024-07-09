class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long waitingTime = 0;
        int busyTill = 0;
        int n = customers.size();
        for(int i = 0;i<n;i++) {
            int time = customers[i][0];
            int prepTime = customers[i][1];
            waitingTime += max(busyTill, time) + prepTime - time;
            busyTill = max(busyTill, time) + prepTime;
        }
        return 1.0 * waitingTime / n;
    }
};