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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> s;
        while (headA) {
            s.emplace(headA);
            headA = headA->next;
        }
        while (headB) {
            auto [itr, did] = s.emplace(headB);
            if (!did) {
                // insertion didn't happen
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
    }
};
