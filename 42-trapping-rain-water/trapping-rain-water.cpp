class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int u = height.size() - 1;
        int leftmax = 0;
        int rightmax = 0;
        int res = 0;

        while(l < u) {
            if(height[l] <= height[u]) {
                if(height[l] > leftmax) leftmax = height[l];
                else {
                    res += leftmax - height[l];
                }
                l++;
            }
            else {
                if(height[u] > rightmax) rightmax = height[u];
                else {
                    res += rightmax - height[u];
                }
                u--;
            }
        }

        return res;

    }
};