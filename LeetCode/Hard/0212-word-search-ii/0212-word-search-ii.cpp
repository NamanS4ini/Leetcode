class TrieNode{
    public:
    TrieNode* next[26] = {};
    bool terminal = false;
};

class Solution {
    unordered_set<string> res;
    TrieNode* node = new TrieNode();
    void insert(string word){
        TrieNode* node = this->node;
        for(char c: word){
            if(!node->next[c-'a'])
                node->next[c-'a'] = new TrieNode();
            node = node -> next[c-'a'];
        }
        node->terminal = true;
    }

    void findWord(vector<vector<char>>& board, int row, int col, TrieNode* node, string s){
        if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0 || board[row][col] == ' ' || !node->next[board[row][col]-'a'])
            return;
        char c = board[row][col];
        board[row][col] = ' ';
        s.push_back(c);
        node = node->next[c-'a'];
        if(node->terminal){
            res.insert(s);
        }
        findWord(board, row + 1, col, node, s);
        findWord(board, row - 1, col, node, s);
        findWord(board, row, col + 1, node, s);
        findWord(board, row, col - 1, node, s);
        board[row][col] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word: words){
            insert(word);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                findWord(board, i, j, node, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};