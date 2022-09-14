class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;

        for (const int a : nums) {
            if (a % 2 == 0) {
                even.emplace_back(a);
            } else {
                odd.emplace_back(a);
            }
        }
        even.insert(even.end(), odd.cbegin(), odd.cend());
        return even;
    }
};
