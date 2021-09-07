class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        const size_t size = arr.size();
        
        int odd = 1;
        int sum = 0;
        for (int odd = 1; odd <= size; odd += 2) {
            for (int i = 0; i < size; ++i) {
                if (i + odd <= size) {
                    for (int j = i; j < i + odd; ++j) {
                        sum += arr[j];
                    }
                }
            }
        }
        return sum;
    }
};