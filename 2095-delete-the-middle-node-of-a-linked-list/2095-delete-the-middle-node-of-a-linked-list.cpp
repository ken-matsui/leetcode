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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 0;
        ListNode* tmp = head;
        while (tmp) {
            tmp = tmp->next;
            ++size;
        }
        if (size == 1) {
            return nullptr;
        }
        
        tmp = head;
        for (int i = 0; i < size/2 - 1; ++i) {
            tmp = tmp->next;
        }
        
        tmp->next = tmp->next->next;
        return head;
    }
};
