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
    ListNode* popMin(vector<ListNode*>& lists) {
        int i = 0;

        int minIdx = i;
        while (!lists[i] && i < lists.size()) {
            ++i;
        }
        minIdx = i;

        for (; i < lists.size(); ++i) {
            if (lists[i] && lists[minIdx]->val > lists[i]->val) {
                minIdx = i;
            }
        }

        ListNode* minNode = lists[minIdx];
        if (lists[minIdx]) {
            lists[minIdx] = lists[minIdx]->next;
        }

        return minNode;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        ListNode* res = new ListNode(0);
        ListNode* tmp = res;

        while (any_of(lists.cbegin(), lists.cend(),
                      [](ListNode* node) { return node != nullptr; })) {
            ListNode* minNode = popMin(lists);
            if (!minNode) {
                break;
            }
            tmp->next = new ListNode(minNode->val);
            tmp = tmp->next;
        }

        return res->next;
    }
};
