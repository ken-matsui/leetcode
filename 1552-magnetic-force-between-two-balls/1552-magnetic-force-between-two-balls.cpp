class Solution {
    int count(vector<int>& position, int d) {
        int ans = 1;
        int cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ++ans;
                cur = position[i];
            }
        }
        return ans;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int lo = 0;
        int hi = position.back() - position.front();

        while (lo < hi) {
            int mi = hi - (hi - lo) / 2;
            if (count(position, mi) >= m) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return lo;
    }
};
