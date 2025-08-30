class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> subBox(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char val = board[i][j];
                int boxIndex = (i/3) * 3 + (j/3);
                if (val != '.') {
                    if (rows[i].find(val) == rows[i].end() &&
                        cols[j].find(val) == cols[j].end() &&
                        subBox[boxIndex].find(val) == subBox[boxIndex].end()) {
                        rows[i].insert(val);
                        cols[j].insert(val);
                        subBox[boxIndex].insert(val);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};