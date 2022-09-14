class Solution {
public:
    int maxDepth(string s) {
        int max_count = 0;
        int count = 0;

        for (const char cur : s) {
            if (cur == '(') {
                ++count;
            } else if (cur == ')') {
                --count;
            }
            if (count > max_count) {
                max_count = count;
            }
            
            if (cur != '(' && cur != ')') {
                continue;
            }
        }

        return max_count;
    }
};
