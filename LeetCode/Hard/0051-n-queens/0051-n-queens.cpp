class Solution {
    void updateQueenNA(int& row, int& col, vector<vector<int>>& queenNA, int queen, int val){
        int n = queenNA.size();
        for(int i = 0; i < n; i++){
            if(queenNA[i][col] == 0 || queenNA[i][col] == queen)
                queenNA[i][col] = val;
            if(queenNA[row][i] == 0 || queenNA[row][i] == queen)
                queenNA[row][i] = val;
        }
        // UP-LEFT
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0){
            if(queenNA[i][j] == 0 || queenNA[i][j] == queen)
                queenNA[i][j] = val;
            i--;
            j--;
        }
        // UP-RIGHT
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < n){
            if(queenNA[i][j] == 0 || queenNA[i][j] == queen)
                queenNA[i][j] = val;
            i--;
            j++;
        }
        // DOWN-RIGHT
        i = row + 1;
        j = col + 1;
        while(i < n && j < n){
            if(queenNA[i][j] == 0 || queenNA[i][j] == queen)
                queenNA[i][j] = val;
            i++;
            j++;
        }
        // DOWN-LEFT
        i = row + 1;
        j = col - 1;
        while(i < n && j >= 0){
            if(queenNA[i][j] == 0 || queenNA[i][j] == queen)
                queenNA[i][j] = val;
            i++;
            j--;
        }
    }
    void solve(int& n, vector<vector<string>>& ans, vector<string>& out, int row, int col, int queens, vector<vector<int>>& queenNA){
        if(queens == n){
            ans.push_back(out);
            return;
        }
        for(int i = row; i < n; i++){
            for(int j = col; j < n; j++){
                if(queenNA[i][j] == 0){
                    queens++;
                    out[i][j] = 'Q';
                    updateQueenNA(i,j, queenNA, queens, queens);
                    solve(n, ans, out, i, j, queens, queenNA);
                    updateQueenNA(i,j, queenNA, queens, 0);
                    out[i][j] = '.';
                    queens--;
                }
            }
            col = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> queenNA(n, vector<int>(n,0));
        vector<string> out(n, string(n,'.'));
        solve(n, ans, out, 0, 0, 0, queenNA);
        return ans;
    }
};


// Fix duplicates "u"