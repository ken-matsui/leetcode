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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // cycle detection
        do {
            slow = slow->next; // once
            if (!fast->next) {
                return false; // reached to null, no cycle
            }
            fast = fast->next->next; // twice
        } while (slow != fast && slow && fast);

        if (!slow || !fast) {
            // reached to null, no cycle
            return false;
        }
        return true;
    }
};