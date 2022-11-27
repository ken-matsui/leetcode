class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            try {
                std::string str = std::to_string(x);
                const std::size_t size = str.size();
            
                if (size == 1) {
                    return true;
                } else if (size == 2) {
                    return str[0] == str[1];
                } else if (size == 3) {
                    return str[0] == str[2];
                } else {
                    const std::size_t range = size - 1; // size == 4 => 3
                    const std::size_t split_line = range - 2; // size == 4 => 1
                
                    for (int i = 0; i <= split_line; ++i) {
                        const bool is_same = str[i] == str[range - i];
                        if (!is_same) {
                            return false;
                        }
                    }

                    return true;
                }
            } catch (...) {
                return false;
            }
        }
    }
};