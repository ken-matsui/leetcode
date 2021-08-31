#include <cmath>
#include <string>

class Solution {
public:
    int reverse(int x) {
        try {
            const bool is_negative = x < 0;
        
            std::string str = std::to_string(std::abs(x));
            std::reverse(str.begin(), str.end());
        
            const int val = std::stoi(str);
            return is_negative ? val * -1 : val;
        } catch (...) {
            return 0;
        }
    }
};