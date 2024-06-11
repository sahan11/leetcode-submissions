class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        
        for(int i = 0;i<n;i++) {
            if(st.empty() || asteroids[i] > 0) st.push(asteroids[i]);
            else if(st.top() < 0 && asteroids[i] < 0) st.push(asteroids[i]);
            else {
                if(abs(st.top()) > abs(asteroids[i])) continue;
                else if(abs(st.top()) == abs(asteroids[i])) st.pop();
                else {
                    st.pop();
                    i--;
                }
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
    }
};