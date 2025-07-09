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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = new ListNode;
        temp = head;
        int value = 0;
        while(head->next != nullptr){
            value++;
            head = head->next;
        }
        for(int i = 0; i < ceil((value+1)/2); i++){
            temp = temp->next;
        }
        return temp;
    }
};