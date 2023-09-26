class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& t : tokens) {
            if (isdigit(t.back())) {
                st.push(stoi(t));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                switch (t[0]) {
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