class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            
            int totalHours = 0;
            for (int pile : piles) {
                totalHours += (pile / mi) + (pile % mi ? 1 : 0);
            }
            if (totalHours <= h) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};