class Solution {
    // infix -> postfix
    string shuntingYard(const string& s) {
        string out;

        stack<char> ops;
        char prev = ' '; // for unary minus
        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (c == ' ') {
                continue;
            } else if (isdigit(c)) {
                while (i < s.size() && isdigit(s[i])) {
                    out += s[i];
                    ++i;
                }
                out += ' '; // delimiter
                --i;
            } else if (c == '+' || c == '-') {
                if (c == '-' &&
                    (i == 0 || prev == '(' || prev == '+' || prev == '-')) {
                    // handle unary minus
                    out += "0 "; // add zero before the unary minus
                }
                while (!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
                    out += ops.top();
                    out += " "; // delimiter for postfix
                    ops.pop();
                }
                ops.push(c);
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    out += ops.top();
                    out += " "; // delimiter for postfix
                    ops.pop();
                }
                ops.pop(); // pop '('
            }
            prev = c;
        }
        while (!ops.empty()) {
            out += ops.top();
            out += " "; // delimiter for postfix
            ops.pop();
        }

        return out;
    }

    int evaluatePostfix(const string& s) {
        stack<int> st;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (isdigit(c)) {
                string n;
                while (i < s.size() && s[i] != ' ') {
                    n += s[i];
                    ++i;
                }
                st.push(stoi(n));
            } else if (c != ' ') {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                switch (c) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                }
            }
        }
        return st.top();
    }

public:
    int calculate(string s) {
        const string postfix = shuntingYard(s);
        return evaluatePostfix(postfix);
    }
};
