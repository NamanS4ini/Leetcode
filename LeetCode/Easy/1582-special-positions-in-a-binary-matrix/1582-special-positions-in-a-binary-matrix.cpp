class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
                    count++;
            }
        }
        return count;
    }
};