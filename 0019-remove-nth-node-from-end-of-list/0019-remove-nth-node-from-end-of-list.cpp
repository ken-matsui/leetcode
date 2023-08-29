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
    void removeNext(ListNode* node) {
        if (node->next == nullptr) {
            return;
        }
        node->next = node->next->next;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;

        int size = 0;
        while (tmp) {
            tmp = tmp->next;
            ++size;
        }
        if (size == 1 && n == 1) {
            return nullptr;
        }
        if (size == n) {
            return head->next;
        }

        int targetIdx = size - n;
        int idx = 0;
        tmp = head;
        for (int i = 0; i < targetIdx - 1; ++i) {
            tmp = tmp->next;
        }
        cout << tmp->val << endl;
        removeNext(tmp);

        return head;
    }
};