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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* next = dummy;
        while (pq.size()) {
            ListNode* l = pq.top();
            pq.pop();
            next->next = l;
            next = next->next;
            if (l && l->next) {
                pq.push(l->next);
            }
        }
        return dummy->next;
    }
    struct compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
};