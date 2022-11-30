class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pair{
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        stack<char> st;
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    st.emplace(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if (st.empty() || st.top() != pair[c]) {
                        return false;
                    }
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};
