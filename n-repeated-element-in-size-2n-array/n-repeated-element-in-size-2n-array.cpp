class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        auto last = A.cend();
        for (auto itr = A.cbegin(); itr != last; ++itr) {
            if (find(itr + 1, last, *itr) != last) {
                return *itr;
            }
        }
        throw -1;
    }
};
​
