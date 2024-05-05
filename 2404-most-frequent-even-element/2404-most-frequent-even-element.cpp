class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            if (n % 2 == 0) {
                freq[n]++;
            }
        }
        if (freq.empty()) {
            return -1;
        }

        int minVal = INT_MAX;
        int maxFreq = INT_MIN;
        for (auto [val, f] : freq) {
            if (f > maxFreq) {
                minVal = val;
                maxFreq = f;
            } else if (val < minVal && f >= maxFreq) {
                minVal = val;
                maxFreq = f;
            }
        }
        cout << endl;
        return minVal;
    }
};
