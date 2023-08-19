class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        vector<vector<int>> ans;
        for(int i = 0;i<n - 1;i++){
            if(i == 0 || (i > 0 && copy[i] != copy[i - 1])){
                int l = i + 1;
                int u = copy.size() - 1;
                int target = 0 - copy[i];
                while(l < u){
                    if(copy[l] + copy[u] == target){
                        vector<int> temp;
                        temp.push_back(copy[i]);
                        temp.push_back(copy[l]);
                        temp.push_back(copy[u]);
                        ans.push_back(temp);

                        while(l < u && copy[l] == copy[l + 1]) l++;
                        while(l < u && copy[u] == copy[u - 1]) u--;
                        l++;
                        u--;
                    }
                    else if(copy[l] + copy[u] < target) l++;
                    else u--;

                    
                }
                
                
            }
        }
        return ans;
    }
};