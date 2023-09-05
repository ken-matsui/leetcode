class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {
        const int rule_index = ruleKey == "type"    ? 0
                               : ruleKey == "color" ? 1
                               : ruleKey == "name"  ? 2
                                                    : -1;

        return std::count_if(items.begin(), items.end(),
                             [&rule_index, &ruleValue](auto& i) {
                                 return i[rule_index] == ruleValue;
                             });
    }
};
