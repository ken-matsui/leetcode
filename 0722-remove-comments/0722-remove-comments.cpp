class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool inBlockComment = false;
        
        vector<string> newSource;
        string cur;
        for (const string& s : source) {
            const int size = s.size();
            
            for (int i = 0; i < size; ++i) {
                if (!inBlockComment && i < size - 1 && s[i] == '/' && s[i + 1] == '/') {
                    // ignore line comment
                    break;
                } else if (!inBlockComment && i < size - 1 && s[i] == '/' && s[i + 1] == '*') {
                    // start `/*`
                    inBlockComment = true;
                    ++i; // skip `*`
                } else if (inBlockComment && i < size - 1 && s[i] == '*' && s[i + 1] == '/') {
                    // end `*/`
                    inBlockComment = false;
                    ++i; // skip `/`
                } else if (!inBlockComment) {
                    cur += s[i];
                }
            }

            if (!inBlockComment && !cur.empty()) {
                newSource.push_back(cur);
                cur = "";
            }
        }
        return newSource;
    }
};
