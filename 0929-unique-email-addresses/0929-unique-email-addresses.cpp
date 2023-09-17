class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;

        for (const string& email : emails) {
            string parsed;
            bool plus = false;
            bool at = false;
            for (char c : email) {
                if (c == '@') {
                    parsed += c;
                    at = true;
                    continue;
                }
                if (at) {
                    parsed += c;
                    continue;
                }
                if (plus && c != '@') {
                    continue;
                }
                if (c == '.') {
                    continue;
                }
                if (c == '+') {
                    plus = true;
                    continue;
                }
                parsed += c;
            }
            set.insert(parsed);
        }

        return set.size();
    }
};
