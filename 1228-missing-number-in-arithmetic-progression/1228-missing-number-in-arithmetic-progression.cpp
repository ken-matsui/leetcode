class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int diff = (arr.back() - arr.front()) / (int)arr.size();
        int expected = arr.front();
        for (int i = 0; i < arr.size(); ++i, expected += diff) {
            if (arr[i] != expected) {
                return expected;
            }
        }
        return expected;
    }
};
