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
        set<ListNode*> visited;
        while (head) {
            auto [ptr, added] = visited.insert(head);
            if (!added) {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};