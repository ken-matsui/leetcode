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
public:
    void deleteVal(ListNode* prev_node, ListNode* head) {
        if (head == nullptr) {
            return;
        } else if (prev_node->val == head->val) {
            ListNode* next_node = head->next;
            delete head;
            prev_node->next = next_node;
            deleteVal(prev_node, next_node);
        } else {
            deleteVal(head, head->next);
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (head != nullptr) {
            deleteVal(head, head->next);
        }
        return head;
    }
};