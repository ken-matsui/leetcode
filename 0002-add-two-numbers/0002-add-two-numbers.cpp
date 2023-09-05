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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;

        int sum = l1->val + l2->val;
        if (sum >= 10) {
            carry = true;
            sum -= 10;
        }

        ListNode* res = new ListNode(sum);
        ListNode* tmp = res;

        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2) {
            int sum = 0;
            if (l1 && l2) {
                sum = l1->val + l2->val;

                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val;

                l1 = l1->next;
            } else {
                sum = l2->val;

                l2 = l2->next;
            }

            if (carry) {
                sum += 1;
            }

            if (sum >= 10) {
                carry = true;
                sum -= 10;
            } else {
                carry = false;
            }

            tmp->next = new ListNode(sum);
            tmp = tmp->next;
        }

        if (carry) {
            tmp->next = new ListNode(1);
            tmp = tmp->next;
        }

        return res;
    }
};
