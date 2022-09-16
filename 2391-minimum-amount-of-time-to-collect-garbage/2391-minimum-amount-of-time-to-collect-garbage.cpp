class Solution {
public:
    void calcMinites(int& minites, const int i, int& carPlace, const int cnt, const vector<int>& travel) {
        if (cnt > 0) { // if found
            minites += cnt;
            // if not the first place, need to calc travel
            if (i != 0) {
                for (int tr = carPlace; tr < i; ++tr) {
                    minites += travel[tr];
                }
                carPlace = i;
            }
        }
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int minites = 0;
        int carPlaceMetal = 0;
        int carPlacePaper = 0;
        int carPlaceGlass = 0;

        const size_t size = garbage.size();
        for (int i = 0; i < size; ++i) {
            const int ms = count(garbage[i].begin(), garbage[i].end(), 'M');
            calcMinites(minites, i, carPlaceMetal, ms, travel);

            const int ps = count(garbage[i].begin(), garbage[i].end(), 'P');
            calcMinites(minites, i, carPlacePaper, ps, travel);

            const int gs = count(garbage[i].begin(), garbage[i].end(), 'G');
            calcMinites(minites, i, carPlaceGlass, gs, travel);
        }
        return minites;
    }
};
