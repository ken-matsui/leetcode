class WordDictionary {
    struct Node {
        bool isTerm = false;
        Node* children[26];
    };

    Node* overallRoot = new Node();

    bool find(Node* root, string word) {
        if (root == nullptr) {
            return false;
        }
        if (word.empty()) {
            return root->isTerm;
        }

        if (word[0] == '.') {
            for (Node* child : root->children) {
                if (find(child, word.substr(1))) {
                    return true;
                }
            }
            return false;
        } else {
            return find(root->children[word[0] - 'a'], word.substr(1));
        }
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        Node* root = overallRoot;
        for (char c : word) {
            if (root->children[c - 'a'] == nullptr) {
                root->children[c - 'a'] = new Node();
            }
            root = root->children[c - 'a'];
        }
        root->isTerm = true;
    }

    bool search(string word) {
        return find(overallRoot, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
