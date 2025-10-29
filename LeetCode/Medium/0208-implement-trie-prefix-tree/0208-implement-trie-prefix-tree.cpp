class TrieNode{
    public:
    char data;
    TrieNode* next[26] = {};
    bool terminal = false;
    TrieNode(char ch){
        data = ch;
    }
    TrieNode(){}
};

class Trie {
    TrieNode* node = new TrieNode();
public:
    void insert(string word) {
        TrieNode* node = this->node;
        for(char c: word){
            if(!node->next[c-'a'])
                node->next[c-'a'] = new TrieNode(c);
            node = node -> next[c-'a'];
        }
        node->terminal = true;
    }
    
    bool search(string word) {
        TrieNode* head = node;
        for(char c: word){
            if(!head -> next[c-'a'])
                return false;
            head = head -> next[c-'a'];
        }
        return head -> terminal;
    }
    bool startsWith(string prefix) {
        TrieNode* head = node;
        for(char c: prefix){
            if(!head -> next[c-'a'])
                return false;
            head = head -> next[c-'a'];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */