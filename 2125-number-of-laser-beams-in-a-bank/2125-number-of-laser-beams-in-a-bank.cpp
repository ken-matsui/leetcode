class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sum = 0;

        int prev_cnt = -1;
        for (const string& b : bank) {
            const int cur_cnt = count(b.begin(), b.end(), '1');
            if (prev_cnt == -1) {
                // first time
                if (cur_cnt == 0) {
                    // skip this time
                    continue;
                } else {
                    prev_cnt = cur_cnt;
                }
            } else {
                // found devices
                if (cur_cnt != 0) {
                    sum += prev_cnt * cur_cnt;
                    prev_cnt = cur_cnt;
                }
            }
        }

        return sum;
    }
};
