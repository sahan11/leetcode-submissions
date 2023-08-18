class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0;
        int rightmax = 0;

        int l = 0;
        int u = n - 1;
        int ans = 0;
        while(l < u){
            if(height[l] <= height[u]){
                if(height[l] <= leftmax){
                    ans += leftmax - height[l];
                }
                else{
                    leftmax = height[l];
                }
                    l++;
            }
            else{
                if(height[u] <= rightmax){
                    ans += rightmax - height[u];
                    
                }
                else{
                    rightmax = height[u];
                }
                u--;
            }
        }
        return ans;
    }
};