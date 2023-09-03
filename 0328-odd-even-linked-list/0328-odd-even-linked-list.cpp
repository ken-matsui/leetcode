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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            // no node case
            return nullptr;
        } else if (!head->next) {
            // one node case
            return head;
        }

        ListNode* oddPtr = head;
        ListNode* evenHead = head->next;
        ListNode* evenPtr = head->next;
        while (oddPtr->next && evenPtr->next) {
            oddPtr->next = oddPtr->next->next;
            evenPtr->next = evenPtr->next->next;

            // iterate
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = evenHead;
        return head;
    }
};
