class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                m[nums[i + 1]]++;
            }
        }

        int maxFreq = INT_MIN;
        int maxVal = INT_MIN;
        for (const auto& [target, count] : m) {
            if (count > maxFreq) {
                maxFreq = count;
                maxVal = target;
            }
        }
        return maxVal;
    }
};
