class Solution {
    int m;
    int n;

    void markSafe(vector<vector<char>>& board, const int i, const int j) {
        board[i][j] = '/'; // mark as safe

        // bottom
        if (i + 1 < m && board[i + 1][j] == 'O') {
            markSafe(board, i + 1, j);
        }
        // up
        if (i - 1 >= 0 && board[i - 1][j] == 'O') {
            markSafe(board, i - 1, j);
        }
        // right
        if (j + 1 < n && board[i][j + 1] == 'O') {
            markSafe(board, i, j + 1);
        }
        // left
        if (j - 1 >= 0 && board[i][j - 1] == 'O') {
            markSafe(board, i, j - 1);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // perimeters and connected nodes are safe
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                markSafe(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                markSafe(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                markSafe(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                markSafe(board, i, n - 1);
            }
        }

        // convert all O's to X's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // revert all /'s to O's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '/') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
