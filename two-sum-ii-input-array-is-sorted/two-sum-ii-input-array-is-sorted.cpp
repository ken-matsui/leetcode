class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t size = numbers.size();
        for (int i = 0; i < size; ++i) {
            const int n = numbers[i];
            const int required = target - n;

            auto it = std::lower_bound(numbers.begin() + i + 1, numbers.end(), required);
            if (it != numbers.end() && *it == required) {
                size_t pos = std::distance(numbers.begin(), it);
                return {i + 1, static_cast<int>(pos + 1)};
            }
        }
        return {0};
    }
};