class Solution {
    vector<vector<int>> visited;
    bool findWord(vector<vector<char>>& board, string& word, int br, int bc,
                  int idx) {
        if (br >= board.size() || bc >= board[0].size() || br < 0 || bc < 0 ||
            board[br][bc] != word[idx])
            return false;
        char temp = board[br][bc];
        board[br][bc] = '.';
        if (idx == word.length() - 1)
            return true;
        if (findWord(board, word, br + 1, bc, idx + 1) ||
            findWord(board, word, br - 1, bc, idx + 1) ||
            findWord(board, word, br, bc + 1, idx + 1) ||
            findWord(board, word, br, bc - 1, idx + 1))
            return true;
        board[br][bc] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0])
                    if (findWord(board, word, i, j, 0)) {
                        return true;
                    }
            }
        }
        return false;
    }
};