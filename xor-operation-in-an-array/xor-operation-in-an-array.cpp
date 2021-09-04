class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = start; n > 0; i += 2, --n) {
            ans = ans ^ i;
        }
        return ans;
    }
};