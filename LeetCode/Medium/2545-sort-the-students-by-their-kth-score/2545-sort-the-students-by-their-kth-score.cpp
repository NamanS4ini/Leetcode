class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        for(int i = 0; i < score.size()-1; i++){
            int index = i;
            for(int j = i + 1; j < score.size(); j++){
            if(score[index][k] < score[j][k]){
                index = j;
            }}
            swap(score[i], score[index]);
        }
        return score;
    }
};