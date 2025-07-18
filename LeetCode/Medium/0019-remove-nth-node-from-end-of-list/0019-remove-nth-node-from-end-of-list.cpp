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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == nullptr || head == nullptr){
            return nullptr;
        }
        ListNode* right = head;
        for(int i = 1; i < n; i++){
            right = right -> next;
        }
        ListNode* left = new ListNode(0, head);
        while(right != nullptr && right -> next != nullptr){
            left = left -> next;
            right = right -> next;
        }
        ListNode* temp = left -> next;
        left -> next = temp -> next;
        if(temp == head){
            head = head->next;
        }
        else{
            delete temp;
        }
    return head;
    }
};