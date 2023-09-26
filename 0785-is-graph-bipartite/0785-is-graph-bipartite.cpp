class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);

        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] != -1) {
                continue;
            }

            stack<int> st;
            st.push(i);
            colors[i] = 0;

            while (!st.empty()) {
                const int node = st.top();
                st.pop();

                for (const int neighbor : graph[node]) {
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
