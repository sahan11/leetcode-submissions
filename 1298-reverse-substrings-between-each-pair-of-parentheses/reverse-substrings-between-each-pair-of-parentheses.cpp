class Solution {
public:

    void reorderStack(stack<char> &st) {
        queue<char> q;
        while(st.top() != '(') {
            char ch = st.top();
            q.push(ch);
            st.pop();
        }
        st.pop();
        while(!q.empty()) {
            st.push(q.front());
            q.pop();
        }
    }
    string reverseParentheses(string s) {
        stack<char> st;
        

        for(int i = 0;i<s.size();i++) {
            if(s[i] == ')') {
                reorderStack(st);
            }
            else {
                st.push(s[i]);
            }
        }

        string new_str = "";
        while(!st.empty()) {
            new_str = st.top() + new_str;
            st.pop();
        }
        return new_str;
    }
};