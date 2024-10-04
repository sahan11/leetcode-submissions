class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        if(n & 1) return -1;
        int sum = skill[0] + skill[n - 1];
        long long ans = skill[0] * skill[n - 1];
        for(int i = 1;i < (n/2);i++) {
            if(skill[i] + skill[n - i - 1] == sum) ans += skill[i] * skill[n - 1 - i];
            else return -1;
        }

        return ans;
    }
};