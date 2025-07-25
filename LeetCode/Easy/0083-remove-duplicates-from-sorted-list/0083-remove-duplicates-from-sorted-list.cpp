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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != nullptr){
            if(prev->val == curr ->val){
                ListNode* temp = curr;
                prev->next = temp ->next;
                curr = curr->next;
                delete temp;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;

    }
};