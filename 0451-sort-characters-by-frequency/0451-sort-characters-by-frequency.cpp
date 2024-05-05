class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        priority_queue<pair<int, char>> q;
        for (auto [c, freq] : m) {
            q.push(make_pair(freq, c));
        }
        
        string res;
        while (!q.empty()) {
            auto [freq, c] = q.top();
            q.pop();
            res += string(freq, c);
        }
        return res;
    }
};
