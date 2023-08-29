/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode* slow = head; // once
        ListNode* fast = head; // twice
        
        // cycle detection algo
        do {
            slow = slow->next;
            if (!fast->next) {
                return nullptr;
            }
            fast = fast->next->next;
        } while (slow != fast && slow && fast);

        // no cycle detection
        if (!slow || !fast) {
            return nullptr;
        }
        
        // cycle detection pos
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
