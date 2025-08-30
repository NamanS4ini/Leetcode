class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                char curr = board[i][j];
                if (curr == '.') {
                    continue;
                }
                int boxIndex = (i/3) * 3 + (j/3);
                if (!rows[i].count(curr) && !cols[j].count(curr) && !boxes[boxIndex].count(curr)) {
                    rows[i].insert(curr);
                    cols[j].insert(curr);
                    boxes[boxIndex].insert(curr);
                } else {
                    return false;
                }
            }
        }
        return true;
    } 
};