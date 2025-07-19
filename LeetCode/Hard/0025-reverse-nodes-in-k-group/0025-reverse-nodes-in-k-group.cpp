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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* firstPrev = new ListNode(0, head);
        ListNode* dummy = firstPrev;
        ListNode* last = head;
        ListNode* first = head;
        while (last != nullptr) {
            for (int i = 1; i < k && last != nullptr; i++) {
                last = last->next;
            }
            if (last != nullptr) {

                ListNode* lastNext = last->next;
                ListNode* curr = first;
                ListNode* dumf = first;
                ListNode* prev = lastNext;
                while (curr != lastNext) {
                    curr = curr->next;
                    first->next = prev;
                    prev = first;
                    first = curr;
                }
                firstPrev -> next = prev;
                firstPrev = dumf;
                last = lastNext;
            }
        }
        return dummy -> next;
    }
};