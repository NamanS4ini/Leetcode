class Solution {
    bool isSfe(vector<string>& out, int row, int col){
        int n = out.size();
        for(int i = 0; i < n; i++){
            if(out[i][col] == 'Q')
                return false;
            if(out[row][i] == 'Q')
                return false;
        }
        // UP-LEFT
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0){
            if(out[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        // UP-RIGHT
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < n){
            if(out[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        // DOWN-RIGHT
        i = row + 1;
        j = col + 1;
        while(i < n && j < n){
            if(out[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        // DOWN-LEFT
        i = row + 1;
        j = col - 1;
        while(i < n && j >= 0){
            if(out[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int& n, vector<vector<string>>& ans, vector<string>& out, int row, int queens){
        if(queens == n){
            ans.push_back(out);
            return;
        }
        for(int j = 0; j < n; j++){
                if(isSfe(out, row, j)){
                    queens++;
                    out[row][j] = 'Q';
                    solve(n, ans, out, row + 1, queens);
                    out[row][j] = '.';
                    queens--;
                }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> out(n, string(n,'.'));
        solve(n, ans, out, 0, 0);
        return ans;
    }
};


// Fix duplicates "u"
// instead of keeping track og each tile for each tile check if it safe to put queen there if theres a queen in the diagonal or L-R, U-D then is not safe  