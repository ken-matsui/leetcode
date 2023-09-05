class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();

        int expected = 0;
        for (int i = 1; i <= size; ++i) {
            expected += i;
        }

        int actual = 0;
        for (int n : nums) {
            actual += n;
        }

        return expected - actual;
    }
};
