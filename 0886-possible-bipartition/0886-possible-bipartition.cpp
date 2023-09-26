class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : dislikes) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != -1) {
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
                        colors[neighbor] = colors[node] ^ 1;
                        st.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
