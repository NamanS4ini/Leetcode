/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    vector<Node*> nodes = vector<Node*>(100, NULL);
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(nodes[node->val - 1])
            return nodes[node->val - 1];
        Node* newNode = new Node(node->val);
        nodes[newNode->val - 1] = newNode;
        for(Node* n: node-> neighbors){
            Node* neighbor = cloneGraph(n);
            if(neighbor){
                newNode->neighbors.push_back(neighbor);
            }
        }
        return newNode;
    }
};