class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.cbegin(), nums.cend());

        int longest = 0;

        for (const int num : nums) {
            // only find the minimum streak start to make it O(n)
            if (set.find(num-1) == set.cend()) {
                int curNum = num;
                int current = 1;
                
                // calc consecutive
                while (set.find(curNum+1) != set.cend()) {
                    ++curNum;
                    ++current;
                }
                longest = max(longest, current);
            }
        }

        return longest;
    }
};