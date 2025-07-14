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
    int getDecimalValue(ListNode* head) {
        string binary = "";
        while(head != nullptr){
            binary += to_string(head -> val);
            head = head-> next;
        }
        int ans = 0;
        int power = 0;
        for(int i = binary.length()-1; i >= 0; i--){
            ans += (binary[i] - '0') * pow(2,power);
            power++; 
        }
        return ans;
    }
};