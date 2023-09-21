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
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode* node = head;
        while (node) {
            node = node->next;
            ++size;
        }
        const int until = size / 2;
        
        stack<int> st;
        node = head;
        for (int i = 0; i < until; ++i) {
            st.push(node->val);
            node = node->next;
        }
        
        if (size % 2 == 1) {
            // drop center
            node = node->next;
        }
        
        for (int i = 0; i < until; ++i) {
            const int val = st.top();
            st.pop();
            if (node->val != val) {
                return false;
            }
            node = node->next;
        }
        return true;
    }
};