class Solution {
    bool isSfe(vector<string>& board, int row, int col){
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q')
                return false;
            if(board[row][i] == 'Q')
                return false;
        }
        // UP-LEFT
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        // UP-RIGHT
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        // DOWN-RIGHT
        i = row + 1;
        j = col + 1;
        while(i < n && j < n){
            if(board[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        // DOWN-LEFT
        i = row + 1;
        j = col - 1;
        while(i < n && j >= 0){
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int& n, vector<vector<string>>& ans, vector<string>& board, int row, int queens){
        if(queens == n){
            ans.push_back(board);
            return;
        }
        for(int i = row; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isSfe(board, i, j)){
                    queens++;
                    board[i][j] = 'Q';
                    solve(n, ans, board, i, queens);
                    board[i][j] = '.';
                    queens--;
                }
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        solve(n, ans, board, 0, 0);
        return ans;
    }
};


// Fix duplicates "u"
// instead of keeping track og each tile for each tile check if it safe to put queen there if theres a queen in the diagonal or L-R, U-D then is not safe  