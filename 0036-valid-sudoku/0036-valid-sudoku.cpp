class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // we assume 9x9

        // by col
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> col_set;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto [itr, did] = col_set.insert(board[i][j]);
                if (!did) {
                    return false;
                }
            }
        }

        // by row
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row_set;
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                auto [itr, did] = row_set.insert(board[j][i]);
                if (!did) {
                    return false;
                }
            }
        }

        // by 3x3
        for (int i_offset = 0; i_offset < 9; i_offset += 3) {
            for (int j_offset = 0; j_offset < 9; j_offset += 3) {
                unordered_set<char> set;
                for (int i = i_offset; i < i_offset + 3; ++i) {
                    for (int j = j_offset; j < j_offset + 3; ++j) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        auto [itr, did] = set.insert(board[i][j]);
                        if (!did) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
