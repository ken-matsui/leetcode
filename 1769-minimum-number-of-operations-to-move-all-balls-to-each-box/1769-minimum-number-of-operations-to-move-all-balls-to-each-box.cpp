class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> sum;

        const size_t size = boxes.size();
        for (int i = 0; i < size; ++i) {
            int diff = 0;
            
            for (int j = 0; j < size; ++j) {
                if (j == i) {
                    continue;
                }
                
                if (boxes[j] == '1') {
                    diff += abs(i - j);
                }
            }

            sum.emplace_back(diff);
        }

        return sum;
    }
};
