class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int maxWidth = -1;

        const size_t size = points.size();
        for (int i = 0; i < size - 1; ++i) {
            const int width = points[i + 1][0] - points[i][0];
            if (width > maxWidth) {
                maxWidth = width;
            }
        }
        return maxWidth;
    }
};
