class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int ind1 = 0;
        int ind2 = 0;
        while(ind1 < m && ind2 < n){
            if(nums1[ind1] < nums2[ind2]){
                nums.push_back(nums1[ind1++]);
            }
            else{
                nums.push_back(nums2[ind2++]);
            }
        }
        while(ind1<m){
            nums.push_back(nums1[ind1++]);
        }
        while(ind2 < n){
            nums.push_back(nums2[ind2++]);
        }
        nums1 = nums;
    }
};