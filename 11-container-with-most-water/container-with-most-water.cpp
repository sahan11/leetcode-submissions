class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftmax = 0;
        int rightmax = n - 1;

        int l = 0;
        int u = height.size() - 1;
        int ans = 0;
        while(l < u){
            if(height[l] <= height[u]){
                if(height[l] >= height[leftmax]){
                    ans = max(min(height[u], height[l]) * (u - l), ans);
                    leftmax = l;
                }
                l++;
            }
            else{
                if(height[u] >= height[rightmax]){
                    ans = max(min(height[u], height[l]) * (u - l), ans);
                    rightmax = u;
                }
                u--;
            }
        }
        return ans;
    }
};