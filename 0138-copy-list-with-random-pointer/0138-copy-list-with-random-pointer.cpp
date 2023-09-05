/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodes; // original -> new
        Node* res = new Node(head->val);
        nodes[head] = res;

        // fill next's
        Node* resPtr = res;
        Node* headPtr = head;
        while (headPtr->next) {
            Node* newNode = new Node(headPtr->next->val);
            nodes[headPtr->next] = newNode;
            resPtr->next = newNode;

            headPtr = headPtr->next;
            resPtr = resPtr->next;
        }

        // fill random's
        resPtr = res;
        headPtr = head;
        while (headPtr && resPtr) {
            if (!headPtr->random) {
                headPtr = headPtr->next;
                resPtr = resPtr->next;
                continue;
            }

            resPtr->random = nodes[headPtr->random];

            headPtr = headPtr->next;
            resPtr = resPtr->next;
        }

        return res;
    }
};
