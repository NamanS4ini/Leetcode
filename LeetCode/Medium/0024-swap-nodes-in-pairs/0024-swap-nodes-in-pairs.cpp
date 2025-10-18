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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode* dummy = head -> next;
        ListNode* prev = NULL;
        while(head && head -> next){
            ListNode* next = head -> next;
            head -> next = next -> next;
            next -> next = head;
            if(prev)
                prev -> next = next;
            prev = head;
            head = head -> next;
        }
        return dummy;
    }
};