class Trie {
    Trie* next[26] = {};
    bool terminal;
public:
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word){
            if(!node->next[c-'a'])
                node->next[c-'a'] = new Trie();
            node =  node->next[c-'a'];
        }
        node->terminal = true;
    }
    
    bool search(string word) {
        Trie* head = this;
        for(char c: word){
            if(!head->next[c-'a'])
                return false;
            head = head->next[c-'a'];
        }
        return head->terminal;
    }
    
    bool startsWith(string prefix) {
        Trie* head = this;
        for(char c: prefix){
            if(!head->next[c-'a'])
                return false;
            head = head->next[c-'a'];
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