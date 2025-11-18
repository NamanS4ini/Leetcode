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
    unordered_map<Node*, Node*> nodes;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(nodes[node])
            return nodes[node];
        Node* newNode = new Node(node->val);
        nodes[node] = newNode;
        for(Node* n: node-> neighbors){
            Node* neighbor = cloneGraph(n);
            if(neighbor){
                newNode->neighbors.push_back(neighbor);
            }
        }
        return newNode;
    }
};