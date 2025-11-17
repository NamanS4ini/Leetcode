class Solution {
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row  < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;
        if(grid[row][col] == '0' || visited[row][col])
            return;
        visited[row][col] = true;
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        this->visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};