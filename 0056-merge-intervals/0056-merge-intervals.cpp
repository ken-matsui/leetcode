class Solution {
    size_t isize;

public:
    int findEnd(const vector<vector<int>>& intervals, int& i, const int prev) {
        if (i + 1 < isize && prev >= intervals[i + 1][0]) {
            ++i;
            return findEnd(intervals, i, max(prev, intervals[i][1]));
        }
        return prev;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        isize = intervals.size();
        vector<vector<int>> output;
        for (int i = 0; i < isize; ++i) {
            output.push_back(
                {intervals[i][0], findEnd(intervals, i, intervals[i][1])});
        }
        return output;
    }
};
