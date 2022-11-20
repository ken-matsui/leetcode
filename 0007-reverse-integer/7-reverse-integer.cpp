class Solution {
public:
    int reverse(int x) {
        try {
            const bool is_negative = x < 0;
        
            string str = to_string(abs(x));
            std::reverse(str.begin(), str.end());
        
            const int val = stoi(str);
            return is_negative ? val * -1 : val;
        } catch (...) {
            return 0;
        }
    }
};
