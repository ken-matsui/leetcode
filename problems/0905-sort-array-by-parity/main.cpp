class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;

        for (const auto& a : A) {
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

