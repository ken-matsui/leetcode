class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        
        unordered_set<int> val;
        while (n != 1 && val.find(n) == val.end()) {
            val.insert(n);

            string s = to_string(n);
            n = 0;
            for (char c : s) {
                n += (c - '0') * (c - '0');
            }
        }
        return n == 1;
    }
};
