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
        ListNode* dummy = NULL;
        ListNode* prev = NULL;

        unordered_map<int, bool> inArr;
        for(int num: nums){
            inArr[num] = true;
        }
        while(head){
            if(!inArr[head->val]){
                if(prev){
                    prev -> next = head;
                }
                if(!dummy)
                    dummy = head;
                prev = head;
            }
            head = head-> next;
        }
        prev -> next = NULL;
        return dummy;
    }
};