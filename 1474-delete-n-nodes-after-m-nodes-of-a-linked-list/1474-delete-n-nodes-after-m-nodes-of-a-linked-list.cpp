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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* headPtr = head;
        ListNode* prev = nullptr;

        while (headPtr) {
            // Move `m`
            for (int i = 0; i < m && headPtr; ++i) {
                prev = headPtr;
                headPtr = headPtr->next;
            }

            // Move `n`
            for (int i = 0; i < n && headPtr; ++i) {
                headPtr = headPtr->next;
            }

            // Delete `n`
            prev->next = headPtr;
        }

        return head;
    }
};
