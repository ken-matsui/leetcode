class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        auto last = nums.cend();
        for (auto itr = nums.cbegin(); itr != last; ++itr) {
            if (find(itr + 1, last, *itr) != last) {
                return *itr;
            }
        }
        throw -1;
    }
};
