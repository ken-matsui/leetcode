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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* headPtr = head;
        int size = 0;
        while (headPtr) {
            headPtr = headPtr->next;
            ++size;
        }

        ListNode* kLeftNode = head;
        ListNode* kRightNode = head;

        for (int i = 1; i < k; ++i) {
            kLeftNode = kLeftNode->next;
        }
        for (int i = 0; i < size - k; ++i) {
            kRightNode = kRightNode->next;
        }

        swap(kLeftNode->val, kRightNode->val);
        return head;
    }
};