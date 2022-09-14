class Solution {
public:
    int distance(const int px, const int cx, const int py, const int cy) const {
        return ceil(sqrt(pow(px - cx, 2) + pow(py - cy, 2)));
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> output;
        for (const auto& q : queries) {
            const int cx = q[0];
            const int cy = q[1];
            const int cr = q[2];

            int count = 0;
            for (const auto& p : points) {
                const int px = p[0];
                const int py = p[1];

                if (distance(px, cx, py, cy) <= cr) {
                    ++count;
                }
            }
            output.emplace_back(count);
        }
        return output;
    }
};
