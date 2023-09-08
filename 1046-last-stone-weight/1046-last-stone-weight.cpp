class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (!pq.empty() && pq.size() != 1) {
            const int maxNum = pq.top();
            pq.pop();
            const int maxNum2 = pq.top();
            pq.pop();

            if (maxNum != maxNum2) {
                pq.push(maxNum - maxNum2);
            }
        }

        if (pq.empty()) {
            return 0;
        } else {
            return pq.top();
        }
    }
};
