class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> pq;
        for (int i = 0; i < names.size(); ++i) {
            pq.emplace(heights[i], names[i]);
        }
        
        vector<string> res(names.size());
        for (int i = 0; i < names.size(); ++i) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};