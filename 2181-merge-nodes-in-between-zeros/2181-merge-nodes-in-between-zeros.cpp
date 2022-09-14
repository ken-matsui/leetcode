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
    ListNode* mergeNodes(ListNode* head) {
        // The first value is 0; skipping
        head = head->next;

        ListNode* res;
        ListNode* tmp;
        bool first_time = true;

        int sum = 0;
        while (head) {
            if (head->val != 0) {
                sum += head->val;
            } else {
                if (first_time) {
                    res = new ListNode(sum);
                    tmp = res;
                    first_time = false;
                } else {
                    tmp->next = new ListNode(sum);
                    tmp = tmp->next;
                }
                sum = 0;
            }
            head = head->next;
        }

        return res;
    }
};
