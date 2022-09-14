class Solution {
public:
    bool isStrictlyPalindromic(const int n) {
        for (int base = 2; base <= n - 2; ++base) {
            int num = n;
            vector<int> conv;

            while (num > 0) {
                conv.emplace_back(num % base);
                num /= base;
            }
            const size_t size = conv.size();
            if (size % 2 == 1) {
                return false;
            }

            const size_t half = size / 2;
            for (int start = 0, end = size - 1; start < half && end > half; ++start, --end) {
                if (conv[start] != conv[end]) {
                    return false;
                }
            }
        }

        return true;
    }
};
