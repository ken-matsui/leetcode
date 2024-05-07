class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        for (int i = 0; i < list2.size(); ++i) {
            if (m.contains(list2[i])) {
                pq.emplace(i + m[list2[i]], list2[i]);
            }
        }
        
        vector<string> res;
        int least = pq.top().first;
        do {
            res.push_back(pq.top().second);
            pq.pop();
        } while (!pq.empty() && least == pq.top().first);
        return res;
    }
};