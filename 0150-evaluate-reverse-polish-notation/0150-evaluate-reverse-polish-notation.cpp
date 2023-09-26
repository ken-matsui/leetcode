class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            const string& token = tokens[i];
            if (isdigit(token.back())) {
                st.push(stoi(token));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                switch (token[0]) {
                    case '+':
                        st.push(a + b);
                        break;
                    case '-':
                        st.push(a - b);
                        break;
                    case '*':
                        st.push(a * b);
                        break;
                    case '/':
                        st.push(a / b);
                        break;
                }
            }
        }
        return st.top();
    }
};