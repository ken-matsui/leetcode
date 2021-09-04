class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for (const int& x : edges[0]) {
            for (const int& y : edges[1]) {
                if (x == y) {
                    return x;
                }
            }
        }
        return -1;
    }
};