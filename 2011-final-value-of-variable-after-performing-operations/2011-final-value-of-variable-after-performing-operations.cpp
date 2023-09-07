class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const string& op : operations) {
            if (op[1] == '+') {
                ++x;
            }
            if (op[1] == '-') {
                --x;
            }
        }
        return x;
    }
};