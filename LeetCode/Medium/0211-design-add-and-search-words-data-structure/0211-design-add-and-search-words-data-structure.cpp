class TrieNode{
    public:
    char data;
    vector<TrieNode*> next = vector<TrieNode*>(26, nullptr);
    bool terminal = false;
    TrieNode(char ch){
        data = ch;
    }
    TrieNode(){}
};


class WordDictionary {
    TrieNode* node = new TrieNode();


    bool findWord(TrieNode* node, string word){
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(c == '.'){
                vector<TrieNode*> next = node->next;
                string subWord = word.substr(i+1);
                for(TrieNode* n: next){
                    if(n){
                        if(findWord(n, subWord))
                            return true;
                    }
                }
                return false;
            }
            if(!node->next[c-'a'])
                return false;
            node = node -> next[c-'a'];
        }
        return node -> terminal;
    }

public:
    void addWord(string word) {
        TrieNode* node = this->node;
        for(char c: word){
            if(!node->next[c-'a'])
                node->next[c-'a'] = new TrieNode(c);
            node = node -> next[c-'a'];
        }
        node->terminal = true;
    }
    
    bool search(string word) {
        return findWord(node, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */