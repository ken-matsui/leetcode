class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int, int> pos;
        for (int i = 1; i <= m; ++i) {
            pos[i] = i - 1;
        }

        vector<int> output;
        for (const int q : queries) {
            output.emplace_back(pos[q]);
            
            for (auto& [k, v] : pos) {
                if (v < pos[q]) {
                    ++v;
                }
            }
            pos[q] = 0;
        }
        return output;
    }
};
