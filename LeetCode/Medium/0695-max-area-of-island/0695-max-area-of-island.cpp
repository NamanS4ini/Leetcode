class Solution {
    vector<vector<bool>> visited;
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row  < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;
        if(grid[row][col] == 0 || visited[row][col])
            return 0;
        visited[row][col] = true;
        int curr = dfs(grid, row - 1, col);
        curr += dfs(grid, row + 1, col);
        curr += dfs(grid, row, col - 1);
        curr += dfs(grid, row, col + 1);
        return curr + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        this->visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int curr = dfs(grid, i, j);
                    maxArea = max(curr, maxArea);
                }
            }
        }
        return maxArea;
    }
};