class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        const size_t size = arr.size();

        int sum = 0;
        for (int odd = 1; odd <= size; odd += 2) {
            for (int i = 0; i + odd <= size; ++i) {
                for (int j = i; j < i + odd; ++j) {
                    sum += arr[j];
                }
            }
        }
        return sum;
    }
};
