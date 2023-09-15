class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) {
                continue;
            }

            stack<int> st;
            st.push(i);
            color[i] = 0;
            
            while (!st.empty()) {
                const int node = st.top();
                st.pop();
                
                for (const int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        st.push(neighbor);
                        color[neighbor] = color[node] ^ 1;
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
