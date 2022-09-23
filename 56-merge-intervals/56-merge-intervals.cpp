class Solution {
    size_t isize;

public:
    vector<int> merged(const vector<vector<int>>& intervals, int& i, vector<int>& res) {
        if (i + 1 < isize && res[1] >= intervals[i + 1][0]) {
            ++i;
            res[0] = min(res[0], intervals[i][0]);
            res[1] = max(res[1], intervals[i][1]);
            return merged(intervals, i, res);
        }
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        isize = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){ return a[0] < b[0]; });

        vector<vector<int>> output;
        for (int i = 0; i < isize; ++i) {
            output.push_back(merged(intervals, i, intervals[i]));
        }
        return output;
    }
};
