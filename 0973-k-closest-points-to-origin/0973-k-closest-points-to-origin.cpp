class Solution {
    int dist(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        vector<int> dists(n);
        for (int i = 0; i < n; ++i) {
            dists[i] = dist(points[i]);
        }
        
        sort(dists.begin(), dists.end());
        int distK = dists[k-1];
        
        vector<vector<int>> res(k, vector<int>(2));
        int t = 0;
        for (int i = 0; i < n; ++i) {
            if (dist(points[i]) <= distK) {
                res[t++] = points[i];
            }
        }
        return res;
    }
};