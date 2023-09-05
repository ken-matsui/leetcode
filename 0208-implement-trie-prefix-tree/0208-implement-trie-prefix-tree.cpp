class Trie {
    struct Node {
        bool isTerm = false;
        Node* children[26];
    };

    Node* overallRoot;

    Node* get(string word) {
        Node* root = overallRoot;
        for (char c : word) {
            if (root == nullptr) {
                break;
            }
            root = root->children[c - 'a'];
        }
        return root;
    }

public:
    Trie() {
        overallRoot = new Node();
    }

    void insert(string word) {
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
        Node* root = get(word);
        return root != nullptr && root->isTerm;
    }

    bool startsWith(string prefix) {
        Node* root = get(prefix);
        return root != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
