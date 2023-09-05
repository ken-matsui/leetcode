class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = std::to_string(n);

        int product = 1;
        int sum = 0;
        for (const char c : s) {
            const int x = c - '0';
            product *= x;
            sum += x;
        }
        return product - sum;
    }
};
