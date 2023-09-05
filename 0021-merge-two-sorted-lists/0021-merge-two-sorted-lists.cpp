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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        ListNode* res;
        if (list1 == nullptr) {
            res = new ListNode(list2->val);
            list2 = list2->next;
        } else if (list2 == nullptr) {
            res = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            if (list1->val <= list2->val) {
                res = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                res = new ListNode(list2->val);
                list2 = list2->next;
            }
        }

        ListNode* tmp = res;
        while (!(list1 == nullptr && list2 == nullptr)) {
            if (list1 == nullptr) {
                tmp->next = new ListNode(list2->val);
                tmp = tmp->next;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                tmp->next = new ListNode(list1->val);
                tmp = tmp->next;
                list1 = list1->next;
            } else {
                if (list1->val <= list2->val) {
                    tmp->next = new ListNode(list1->val);
                    tmp = tmp->next;
                    list1 = list1->next;
                } else {
                    tmp->next = new ListNode(list2->val);
                    tmp = tmp->next;
                    list2 = list2->next;
                }
            }
        }
        return res;
    }
};
