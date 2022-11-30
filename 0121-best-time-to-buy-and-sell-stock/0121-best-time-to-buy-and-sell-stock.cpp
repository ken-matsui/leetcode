class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();

        int profit = 0;
        int curPrice = 100000;
        for (int i = 0; i < size; ++i) {
            if (prices[i] < curPrice) {
                curPrice = prices[i];
            }
            const int curProfit = prices[i] - curPrice;
            if (profit < curProfit) {
                profit = curProfit;
            }
        }
        return profit;
    }
};
