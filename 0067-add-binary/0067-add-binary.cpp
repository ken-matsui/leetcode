class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res;

        bool carry = false;
        const int n = min(a.size(), b.size());
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1' && b[i] == '1' && carry) {
                res += '1';
                carry = true;
            } else if (a[i] == '1' && b[i] == '1' || a[i] == '1' && carry ||
                       b[i] == '1' && carry) {
                res += '0';
                carry = true;
            } else if (a[i] == '1' || b[i] == '1' || carry) {
                res += '1';
                carry = false;
            } else {
                res += '0';
                carry = false;
            }
        }

        const int m = max(a.size(), b.size());
        const string c = a.size() > b.size() ? a : b;
        for (int i = n; i < m; ++i) {
            if (c[i] == '1' && carry) {
                res += '0';
                carry = true;
            } else if (c[i] == '1' || carry) {
                res += '1';
                carry = false;
            } else {
                res += '0';
                carry = false;
            }
        }
        if (carry) {
            res += '1';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
