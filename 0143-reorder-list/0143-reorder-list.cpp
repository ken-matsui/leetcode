/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void print(ListNode* node) {
        cout << "[";
        while (node) {
            cout << node->val << ",";
            node = node->next;
        }
        cout << "]" << endl;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* tmp = head;
        while (tmp) {
            tmp = tmp->next;
            ++size;
        }

        for (int i = 0; i < size / 2; ++i) {
            head = head->next;
        }
        return head;
    }

public:
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) {
            return;
        }

        ListNode* halfBack = reverseList(middleNode(head));
        // print(halfBack);
        // print(head);

        // remove the last from halfBack
        ListNode* tmp = halfBack;
        ListNode* prev = tmp;
        while (tmp->next) {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = nullptr;
        // print(halfBack);

        while (head && halfBack) {
            head->next = new ListNode(halfBack->val, head->next);

            halfBack = halfBack->next;
            if (head->next) {
                head = head->next->next;
                // cout << head->val;
            } else {
                head = nullptr;
            }
        }
        // cout << "===" << endl;
    }
};
