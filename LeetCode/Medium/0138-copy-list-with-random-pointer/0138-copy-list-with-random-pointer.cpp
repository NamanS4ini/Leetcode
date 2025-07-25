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
        unordered_map<Node*, Node*> NtN;
        while (head) {
            ans->next = new Node(head->val);
            ans = ans->next;
            NtN[head] = ans;
            head = head->next;
        }

        ans = dummy->next;
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