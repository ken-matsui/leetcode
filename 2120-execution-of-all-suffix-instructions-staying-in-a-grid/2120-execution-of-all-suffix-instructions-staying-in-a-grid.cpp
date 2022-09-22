class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        const size_t size = s.size();
        const vector<int> startPosTmp = startPos;

        vector<int> output;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                if (s[j] == 'R') {
                    startPos[1] += 1;
                    if (startPos[1] < n) {
                        ++sum;
                    } else {
                        break;
                    }
                }
                if (s[j] == 'L') {
                    startPos[1] -= 1;
                    if (startPos[1] >= 0) {
                        ++sum;
                    } else {
                        break;
                    }
                }
                if (s[j] == 'D') {
                    startPos[0] += 1;
                    if (startPos[0] < n) {
                        ++sum;
                    } else {
                        break;
                    }
                }
                if (s[j] == 'U') {
                    startPos[0] -= 1;
                    if (startPos[0] >= 0) {
                        ++sum;
                    } else {
                        break;
                    }
                }
            }
            startPos = startPosTmp;
            output.emplace_back(sum);
        }
        return output;
    }
};
