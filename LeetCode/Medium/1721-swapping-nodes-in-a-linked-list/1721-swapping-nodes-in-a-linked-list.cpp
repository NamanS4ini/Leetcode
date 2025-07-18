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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* begin = head;
        ListNode* right =  head;
        for(int i = 1; i < k; i++){
            begin = begin -> next;
            right = right -> next;
        }
        ListNode* left = head;
        while(right != nullptr && right->next != nullptr){
            right = right-> next;
            left = left ->next;
        }
        int temp = begin -> val;
        begin -> val = left->val;
        left-> val = temp;
        return head;
    }
};