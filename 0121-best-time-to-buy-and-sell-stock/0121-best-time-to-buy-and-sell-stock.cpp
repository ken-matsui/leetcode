class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();

        int curPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < size; ++i) {
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
