class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int top = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    top = i;
                    break;
                }
            }
            if (top != -1)
                break;
        }
        cout << top << endl;
        int left = -1;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (grid[j][i]) {
                    left = i;
                    break;
                }
            }
            if (left != -1)
                break;
        }
        cout << left << endl;
        int right = -1;
        for (int i = cols - 1; i >= 0; i--) {
            for (int j = 0; j < rows; j++) {
                if (grid[j][i]) {
                    right = i;
                    break;
                }
            }
            if (right != -1)
                break;
        }
        cout << right << endl;
        int bottom = -1;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    bottom = i;
                    break;
                }
            }
            if (bottom != -1)
                break;
        }
        cout << bottom << endl;
        return (right - left + 1) * (bottom - top + 1);
    }
};