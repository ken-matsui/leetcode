class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() != 9) {
            *(digits.end() - 1) += 1;
            return digits;
        } else {
            bool carry = true;
            for (auto itr = digits.rbegin(); carry && itr != digits.rend();
                 ++itr) {
                if (*itr == 9) {
                    *itr = 0;
                } else {
                    *itr += 1;
                    carry = false;
                }
            }
            if (carry) {
                vector<int> vec{1};
                for (const int d : digits) {
                    vec.push_back(d);
                }
                return vec;
            }
            return digits;
        }
    }
};
