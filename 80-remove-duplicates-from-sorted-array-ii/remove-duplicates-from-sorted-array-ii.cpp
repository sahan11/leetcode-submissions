class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        int cnt = 0;
        for(auto it : mp){
            for(int i = 0;i<min(2, it.second);i++){
                nums[cnt++] = it.first;
            }
        }
        return cnt;
    }
};