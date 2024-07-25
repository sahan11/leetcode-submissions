class Solution {
public:
    void merge(int l, int mid, int u, vector<int> &nums) {
        int left = l;
        int right = mid + 1;
        vector<int> arr;
        while(left <= mid && right <= u) {
            if(nums[left] > nums[right]) {
                arr.push_back(nums[right]);
                right++;
            }
            else {
                arr.push_back(nums[left]);
                left++;
            }
        }

        while(left <= mid) {
            arr.push_back(nums[left]);
            left++;
        }
        while(right <= u) {
            arr.push_back(nums[right]);
            right++;
        }

        for(int i = l;i<=u;i++) {
            nums[i] = arr[i - l];
        } 
    }
    
    void mergeSort(int l, int u, vector<int> &nums) {
        if(l >= u) return;

        int mid = (l + u) / 2;
        mergeSort(l, mid, nums);
        mergeSort(mid + 1, u, nums);
        merge(l, mid, u, nums);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};