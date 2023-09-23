class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i)
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        sort(cars.begin(), cars.end());

        int res = 0;
        for (int i = n - 1; i > 0; --i) {
            if (cars[i].second < cars[i - 1].second) {
                ++res;
            } else {
                cars[i - 1].second = cars[i].second;
            }
        }
        return res + (n > 0);
    }
};