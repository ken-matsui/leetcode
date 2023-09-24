class Solution {
    int m;
    int n;
    
    bool dfs(vector<vector<char>>& board, const int i, const int j, const string& word, const int idx) {
        if (board[i][j] == '/') {
            // already seen
            return false;
        }
        if (word.size() == idx) {
            // found
            return true;
        }
        const char orig = board[i][j];
        board[i][j] = '/';

        // bottom
        if (i + 1 < m && board[i + 1][j] == word[idx]) {
            if (dfs(board, i + 1, j, word, idx + 1)) {
                return true;
            }
        }
        // up
        if (i - 1 >= 0 && board[i - 1][j] == word[idx]) {
            if (dfs(board, i - 1, j, word, idx + 1)) {
                return true;
            }
        }
        // right
        if (j + 1 < n && board[i][j + 1] == word[idx]) {
            if (dfs(board, i, j + 1, word, idx + 1)) {
                return true;
            }
        }
        // left
        if (j - 1 >= 0 && board[i][j - 1] == word[idx]) {
            if (dfs(board, i, j - 1, word, idx + 1)) {
                return true;
            }
        }
        
        board[i][j] = orig; // revert original
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (word.size() == 1) {
                        return true;
                    }
                    if (dfs(board, i, j, word, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
