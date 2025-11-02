class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));
        int count = m*n;
        for(vector<int> pos: walls){
            grid[pos[0]][pos[1]] = -1;
            count--;
        }
        for(vector<int> pos: guards){
            grid[pos[0]][pos[1]] = -1;
            count--;
        }

        for(vector<int> pos: guards){
            int row = pos[0];
            int col = pos[1];
            for(int i = row - 1; i >= 0; i--){
                if(grid[i][col] == 0 || grid[i][col] == 1){
                    if(grid[i][col] != 1)
                        count--;
                    grid[i][col] = 1;
                }
                else{
                    break;
                }
            }
            for(int i = row + 1; i < m; i++){
                if(grid[i][col] == 0 || grid[i][col] == 1){
                    if(grid[i][col] != 1)
                        count--;
                    grid[i][col] = 1;
                }
                else{
                    break;
                }
            }
            for(int i = col - 1; i >= 0; i--){
                if(grid[row][i] == 0 || grid[row][i] == 1){
                    if(grid[row][i] != 1)
                        count--;
                    grid[row][i] = 1;
                }
                else{
                    break;
                }
            }
            for(int i = col + 1; i < n; i++){
                if(grid[row][i] == 0 || grid[row][i] == 1){
                    if(grid[row][i] != 1)
                        count--;
                    grid[row][i] = 1;
                }
                else{
                    break;
                }
            }
        }
        return count;
        
    }
};