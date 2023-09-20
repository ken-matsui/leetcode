class Solution {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word = "";
    };

    int m;
    int n;
    TrieNode* root = new TrieNode();

    void insertWord(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, const int i, const int j,
             TrieNode* curr, vector<string>& res) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '/') {
            return;
        }

        char c = board[i][j];
        if (!curr->children.count(c)) {
            return;
        }

        curr = curr->children[c];
        if (curr->word != "") {
            res.push_back(curr->word);
            curr->word = "";
        }

        board[i][j] = '/'; // mark as visited
        dfs(board, i + 1, j, curr, res);
        dfs(board, i - 1, j, curr, res);
        dfs(board, i, j + 1, curr, res);
        dfs(board, i, j - 1, curr, res);
        board[i][j] = c; // reset to original
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for (const string& w : words) {
            insertWord(w);
        }

        vector<string> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
};
