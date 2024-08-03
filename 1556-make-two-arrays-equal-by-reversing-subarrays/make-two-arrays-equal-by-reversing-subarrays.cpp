class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) return false;

        map<int, int> mp1;
        map<int, int> mp2;
        for(int i = 0;i<target.size();i++) {
            mp1[target[i]]++;
        }
        for(int i = 0;i<arr.size();i++) {
            mp2[arr[i]]++;
        }
        for(auto it : mp1) {
            if(it.second != mp2[it.first]) return false;
        }
        return true;
    }
};