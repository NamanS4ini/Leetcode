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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* dummy2 = dummy;
        unordered_set<int> inArr;
        for(int num: nums){
            inArr.insert(num);
        }
        while(head){
            if(inArr.find(head->val) == inArr.end()){
                dummy -> next = head;
                dummy = dummy -> next;
            }
            head = head-> next;
        }
        dummy -> next = NULL;
        return dummy2->next;
    }
};