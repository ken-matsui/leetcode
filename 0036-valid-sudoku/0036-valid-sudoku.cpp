class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // by row
        for (int i = 0; i < 9; ++i) {
            
            unordered_set<char> set;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                
                auto [itr, did] = set.insert(board[i][j]);
                if (!did) {
                    return false;
                }
            }
        }
        
        // by col
        for (int j = 0; j < 9; ++j) {

            unordered_set<char> set;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') {
                    continue;
                }
                
                auto [itr, did] = set.insert(board[i][j]);
                if (!did) {
                    return false;
                }
            }
        }

        // by 3x3
        for (int i_os = 0; i_os < 9; i_os += 3) {
            for (int j_os = 0; j_os < 9; j_os += 3) {
                
                unordered_set<char> set;
                for (int i = i_os; i < i_os + 3; ++i) {
                    for (int j = j_os; j < j_os + 3; ++j) {
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