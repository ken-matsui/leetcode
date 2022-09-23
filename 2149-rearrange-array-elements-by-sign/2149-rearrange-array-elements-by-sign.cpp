class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posi;
        vector<int> nega;

        for (const int n : nums) {
            if (n < 0) {
                nega.emplace_back(n);
            } else {
                posi.emplace_back(n);
            }
        }

        const size_t size = posi.size();
        vector<int> output;
        for (int i = 0; i < size; ++i) {
            output.emplace_back(posi[i]);
            output.emplace_back(nega[i]);
        }
        return output;
    }
};
