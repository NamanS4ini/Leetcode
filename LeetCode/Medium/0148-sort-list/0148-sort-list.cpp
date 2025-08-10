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
private:
    ListNode*  merge(ListNode* l1, ListNode* l2){
        ListNode* ans = new ListNode(-1);
        ListNode* dummy = ans;
        while(l1 && l2){
            if(l1->val < l2->val){
                ans->next = l1;
                ans = ans->next;
                l1 = l1-> next;
            }
            else{
                ans->next = l2;
                ans = ans->next;
                l2 = l2 -> next;
            }
        }
        while(l1){
            ans->next = l1;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2){
            ans->next = l2;
            ans = ans->next;
            l2 = l2->next;
        }
        cout << dummy -> next -> val << " ";
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast->next && fast->next->next){
                slow = slow -> next;
                fast = fast->next->next;
            }
            ListNode* right = slow -> next; 
            slow -> next = nullptr; 
            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(right);
            ListNode* result = merge(l1, l2);
            return result;
    }
};