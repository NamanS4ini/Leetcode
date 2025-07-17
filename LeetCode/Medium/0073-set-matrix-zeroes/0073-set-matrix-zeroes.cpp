class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // unordered_map<int, vector<vector<int>> indecies;
        vector<vector<int>> zeroes;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                // if its zero
                if(matrix[i][j] == 0){
                    zeroes.push_back({i,j});
                }
                // // if non zero
                // else{
                //     indecies[1].push_back({i,j});
                // }
            }
        }
        // Make all of the rows zero
        for(int i = 0; i < zeroes.size(); i++){
            for(int j = 0; j < cols; j++){
                matrix[zeroes[i][0]][j] = 0;
            }
        }
        // For all cols
        for(int i = 0; i < zeroes.size(); i++){
            for(int j = 0; j < rows; j++){
                matrix[j][zeroes[i][1]] = 0;
            }
        }
    }
};