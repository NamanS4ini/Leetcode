class Solution {
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row  < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;
        if(grid[row][col] != 1)
            return 0;
        grid[row][col] = 2;
        return dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1) + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int curr = dfs(grid, i, j);
                    maxArea = max(curr, maxArea);
                }
            }
        }
        return maxArea;
    }
};