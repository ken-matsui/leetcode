/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* dfs(Node* prev, Node* cur) {
        if (!cur) {
            return prev;
        }
        cur->prev = prev;
        prev->next = cur;

        Node* tmp = cur->next;

        Node* tail = dfs(cur, cur->child);
        cur->child = nullptr;
        return dfs(tail, tmp);
    }

public:
    Node* flatten(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* prev = new Node(0, nullptr, head, nullptr);
        dfs(prev, head);
        prev->next->prev = nullptr;
        return prev->next;
    }
};
