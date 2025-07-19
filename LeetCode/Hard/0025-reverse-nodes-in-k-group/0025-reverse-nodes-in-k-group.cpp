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
        // Make a node to store the previos node from the one we are currently on
        ListNode* firstPrev = new ListNode(0, head);
        // Make a dummy Node to return coz we are changing head and the firstPrev
        ListNode* dummy = firstPrev;
        ListNode* last = head;
        ListNode* first = head;
        // Run through the whole LL
        while (last != nullptr) {
            // Advance the last node k - 1 times to reach the position
            for (int i = 1; i < k && last != nullptr; i++) {
                last = last->next;
            }
            if (last != nullptr) {
                // Take dummy first node (that will not change) becauses when reversing this node will become the firstPrev
                ListNode* dumf = first;

                // Take the node next of the last sp we can point the first to that node
                ListNode* lastNext = last->next;
                // Reverse the LL
                ListNode* curr = first;
                ListNode* prev = lastNext;
                while (curr != lastNext) {
                    curr = curr->next;
                    first->next = prev;
                    prev = first;
                    first = curr;
                }
                // After reversing point the next of the firstPrev node (the node at n * k pos) to point to the last node
                // Which after the reversal is the last node of the part we reversed
                // This will make the last node connect to the previous of the first node before reversal
                firstPrev -> next = prev;
                // Assign the firstPrev to dumf which will be the new previous after the reversal
                firstPrev = dumf;
                last = lastNext;
            }
        }
        // return dummy -> next coz dummy is created ny us and its next points to the new head
        return dummy -> next;
    }
};