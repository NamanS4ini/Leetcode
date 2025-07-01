class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        for(int in = 0; in < 3; in++){
            for(int i = 0; i < mat.size(); i++){
                for(int j = i; j < mat.size(); j++){
                    swap(mat[j][i], mat[i][j]);
                }
            }

            for(int i = 0; i < mat.size(); i++){
                for(int j = 0; j < mat.size()/2; j++){
                    swap(mat[i][j], mat[i][mat.size()-j-1]);
                }
            }
            if(mat == target) return true;
        }
        return false;
    }
};