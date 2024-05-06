class Solution {
    unordered_map<string, string> month{
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"},
    };

public:
    string reformatDate(string date) {
        string res = date.substr(date.size() - 4, 4);
        res += "-";
        res += month[date.substr(date.size() - 8, 3)];
        res += "-";
        if (!isdigit(date[1])) {
            res += "0";
            res += date[0];
        } else {
            res += date.substr(0, 2);
        }
        return res;
    }
};
