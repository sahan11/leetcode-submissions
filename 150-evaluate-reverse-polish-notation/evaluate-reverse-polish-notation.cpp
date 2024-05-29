class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0;i<n;i++) {
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(tokens[i] == "+") {
                    st.push(a + b);
                }
                if(tokens[i] == "-") {
                    st.push(a - b);
                }
                if(tokens[i] == "*") {
                    st.push(a * b);
                }
                if(tokens[i] == "/") {
                    st.push(a / b);
                }

                
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};