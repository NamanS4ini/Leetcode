class Solution {
    bool isSfe(vector<string>& out, int row, int col) {
        int n = out.size();
        for (int i = 0; i < n; i++) {
            if (out[i][col] == 'Q')
                return false;
            if (out[row][i] == 'Q')
                return false;
        }
        // UP-LEFT
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (out[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        // UP-RIGHT
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if (out[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        // DOWN-RIGHT
        i = row + 1;
        j = col + 1;
        while (i < n && j < n) {
            if (out[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        // DOWN-LEFT
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0) {
            if (out[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int& n, vector<vector<string>>& ans, vector<string>& out,
               int row, int col, int queens) {
        if (queens == n) {
            ans.push_back(out);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSfe(out, i, col)) {
                queens++;
                out[i][col] = 'Q';
                solve(n, ans, out, i, col + 1, queens);
                out[i][col] = '.';
                queens--;
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> out(n, string(n, '.'));
        solve(n, ans, out, 0, 0, 0);
        return ans.size();
    }
};