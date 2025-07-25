/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(-1);
        Node* dummy = ans;
        Node* temp = head;
        while (head) {
            ans->next = new Node(head->val);
            ans = ans->next;
            head = head->next;
        }
        ans = dummy->next;
        dummy = dummy->next;
        unordered_map<Node*, Node*> NtN;
        while (temp) {
            NtN[temp] = dummy;
            temp = temp->next;
            dummy = dummy->next;
        }
        for(auto node: NtN){
            Node* originalNode = node.first;
            Node* copyNode = node.second;
            if(originalNode -> random){
                auto rand = NtN.find(originalNode -> random);
                copyNode -> random = rand -> second;
            }
        }
        return ans;
    }
};