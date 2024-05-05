class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& s : words) {
            freq[s]++;
        }

        auto cmp = [](const pair<int, string>& left,
                      const pair<int, string>& right) {
            if (left.first != right.first) {
                return left.first > right.first;
            }
            return left.second < right.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);
        for (const auto& [s, f] : freq) {
            pq.push(make_pair(f, s));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res(k);
        for (int i = k - 1; i >= 0; --i) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
