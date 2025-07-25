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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow->next;
            fast = fast -> next -> next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        ListNode* next = curr;
        while(curr != nullptr){
            next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        slow -> next = prev;
        while(prev != nullptr){
            if(head -> val != prev -> val){
                return false;
            }
            head = head-> next;
            prev = prev-> next;
        }
        
        return true;
    }
};