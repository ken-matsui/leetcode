class Solution {
public:
    int getNumForRoman(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }

    int romanToIntImpl(const int i, const string& s, const int sum) {
        if (s.size() <= i) {
            return sum;
        }

        switch (s[i]) {
            case 'I':
                // not the last element
                if ((s.size() - 1 != i) && s[i + 1] == 'V' || s[i + 1] == 'X') {
                    return romanToIntImpl(i + 2, s, sum + getNumForRoman(s[i + 1]) - 1);
                } else {
                    return romanToIntImpl(i + 1, s, sum + 1);
                }
            case 'X':
                // not the last element
                if ((s.size() - 1 != i) && s[i + 1] == 'L' || s[i + 1] == 'C') {
                    return romanToIntImpl(i + 2, s, sum + getNumForRoman(s[i + 1]) - 10);
                } else {
                    return romanToIntImpl(i + 1, s, sum + 10);
                }
            case 'C':
                // not the last element
                if ((s.size() - 1 != i) && s[i + 1] == 'D' || s[i + 1] == 'M'){
                    return romanToIntImpl(i + 2, s, sum + getNumForRoman(s[i + 1]) - 100);
                } else {
                    return romanToIntImpl(i + 1, s, sum + 100);
                }
            default:
                return romanToIntImpl(i + 1, s, sum + getNumForRoman(s[i]));
        }
    }

    int romanToInt(string s) {
        return romanToIntImpl(0, s, 0);
    }
};
