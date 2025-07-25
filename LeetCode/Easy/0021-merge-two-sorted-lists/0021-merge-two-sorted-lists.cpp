class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        head -> next = list1 ? list1 : list2;
        return dummy -> next;
    }
};