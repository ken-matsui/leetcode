/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloned) {
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }
        
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;
        vector<Node*> neighbors;
        for (Node* n : node->neighbors) {
            neighbors.push_back(dfs(n, cloned));
        }
        newNode->neighbors = neighbors;
        return newNode;
    }
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        // original -> cloned
        unordered_map<Node*, Node*> cloned;
        return dfs(node, cloned);
    }
};