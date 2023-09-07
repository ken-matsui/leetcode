class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) {
            return 0;
        } else if (stones.size() == 1) {
            return stones[0];
        }
        
        sort(stones.begin(), stones.end(), greater{});
        if (stones[0] == stones[1]) {
            stones.erase(stones.begin(), stones.begin()+2);
        } else {
            stones[0] -= stones[1];
            stones.erase(stones.begin()+1);
        }
        return lastStoneWeight(stones);
    }
};
