class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> help;
        for(int i = 0;i<names.size();i++) {
            help.push_back({heights[i], names[i]});
        }

        sort(help.begin(), help.end(), [](const pair<int, string> a, const pair<int, string> b) {
            return a.first > b.first;
        });
        vector<string> ans;
        for(int i = 0;i<help.size();i++) {
            ans.push_back(help[i].second);
        }
        return ans;
    }
};