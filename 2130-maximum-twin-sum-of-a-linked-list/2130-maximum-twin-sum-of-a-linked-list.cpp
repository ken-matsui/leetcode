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
    void makeVec(ListNode* head, vector<int>& v) {
        if (!head) {
            return;
        }
        v.emplace_back(head->val);
        makeVec(head->next, v);
    }

    int pairSum(ListNode* head) {
        vector<int> v;
        makeVec(head, v);

        int maxSum = -1;
        const size_t size = v.size();
        for (int i = 0; i < size / 2; ++i) {
            const int sum = v[i] + v[size - 1 - i];
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};
