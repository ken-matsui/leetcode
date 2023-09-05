class Codec {
public:
    const string delim = "<:DELIM/>";

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        for (const string& s : strs) {
            ret += s;
            ret += delim;
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        string str;
        for (int idx = 0; idx < s.size(); ++idx) {
            if (s[idx] == '<') {
                if (idx <= s.size() - delim.size()) {
                    // read the following chars
                    if (s[idx + 1] == ':' && s[idx + 2] == 'D' &&
                        s[idx + 3] == 'E' && s[idx + 4] == 'L' &&
                        s[idx + 5] == 'I' && s[idx + 6] == 'M' &&
                        s[idx + 7] == '/' && s[idx + 8] == '>') {
                        ret.emplace_back(str);
                        str = "";
                        idx += delim.size() - 1;
                        continue;
                    }
                }
            }
            str += s[idx];
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
