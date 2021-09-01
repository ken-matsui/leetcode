class Solution {
public:
    bool isOpen(char c) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                return true;
        }
        return false;
    }
    bool isValid(string s) {
        const size_t size = s.size();
        if (size < 2) {
            return false;
        }
        
        char first = s[0];
        if (!isOpen(first)) {
            return false;
        }

        map<char, char> table = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        if (size == 2) {
            return table[first] == s[1];
        }

        string s2{ first };
        for (int i = 1; i < size; ++i) {
            const char c2 = s[i];

            if (isOpen(c2)) {
                s2.push_back(c2);
            } else {
                if (s2.empty()) {
                    return false;
                }
                if (table[s2.back()] == c2) {
                    s2.pop_back();
                } else {
                    return false;
                }
            }
        }
        return s2.empty();
    }
};