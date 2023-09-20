class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        } else if (nums.size() == 1) {
            return {to_string(nums[0])};
        }

        vector<string> res;
        int start = nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if ((long long)nums[i] - (long long)prev != 1LL) {
                if (start != prev) {
                    res.push_back(to_string(start) + "->" + to_string(prev));
                } else {
                    res.push_back(to_string(start));
                }
                start = nums[i];
            }
            prev = nums[i];
        }
        if (start != prev) {
            res.push_back(to_string(start) + "->" + to_string(prev));
        } else {
            res.push_back(to_string(start));
        }
        return res;
    }
};
