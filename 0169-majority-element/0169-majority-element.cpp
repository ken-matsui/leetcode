class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> m;
        int max_num = -1;
        int max_freq = -1;
        for (const int n : nums) {
            m[n]++;
            if (max_freq < m[n]) {
                max_num = n;
                max_freq = m[n];
            }
        }
        return max_num;
    }
};
