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
        ListNode* left = new ListNode(0,head);
        ListNode* right = head;
        // Run thorugh entire LL
        while(right != nullptr && right->next != nullptr){
            // If duplicate is found
            if(right-> val == right->next->val){
                // Temp will be used to delete duplicates
                ListNode* temp = right;
                // SGo ahead until the end of the duplicates
                while(right-> next != nullptr && right -> val == right->next->val){
                    right = right->next;
                }
                // Assigh the next of the last non duplicate we found to the next of the last duplicate
                left->next = right->next;
                // if the duplicate is at head change head to the next of the last duplicate
                if(temp == head){
                    head = left -> next;
                }
                // Detach that part of ll from the original
                right->next = nullptr;
                // Run thorugh the duplicate LL and delete all element in there
                while(temp != nullptr){
                    ListNode* temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                }
                // Assign right to the next of the last non duplicate item for next iteration
                right = left -> next;
            }
            // if the current is not a duplicate go ahead in the LL
            else{
                left = left -> next;
                right = right -> next;
            }
        }
            return head;
    }
};