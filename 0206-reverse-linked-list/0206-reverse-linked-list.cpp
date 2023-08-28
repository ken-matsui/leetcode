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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        vector<int> tmp = {head->val};
        while (head->next) {
            head = head->next;
            tmp.emplace_back(head->val);
        }

        auto it = tmp.rbegin();
        ListNode* rev = new ListNode(*it);
        ListNode* revHead = rev;
        for (++it; it != tmp.rend(); ++it) {
            revHead->next = new ListNode(*it);
            revHead = revHead->next;
        }
        return rev;
    }
};
