class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();

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
                
                for (const int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) {
                        st.push(neighbor);
                        colors[neighbor] = colors[node] ^ 1;
                    } else if (colors[neighbor] == colors[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};