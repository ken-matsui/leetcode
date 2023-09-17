class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                continue;
            }
            if (i > 0 && flowerbed[i - 1] == 1) {
                continue;
            }
            if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1) {
                continue;
            }

            --n;
            flowerbed[i] = 1;
            if (n == 0) {
                return true;
            }
        }
        return n == 0;
    }
};