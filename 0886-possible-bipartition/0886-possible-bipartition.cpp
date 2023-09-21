class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n);
        for (const auto& dl : dislikes) {
            adjList[dl[0] - 1].push_back(dl[1] - 1);
            adjList[dl[1] - 1].push_back(dl[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != -1) {
                // already visited
                continue;
            }
            
            stack<int> st;
            st.push(i);
            colors[i] = 0;
            
            while (!st.empty()) {
                const int node = st.top();
                st.pop();
                
                for (const int neighbor : adjList[node]) {
                    if (colors[neighbor] == -1) {
                        // not visited, color
                        st.push(neighbor);
                        colors[neighbor] = colors[node] ^ 1;
                    } else if (colors[node] == colors[neighbor]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};