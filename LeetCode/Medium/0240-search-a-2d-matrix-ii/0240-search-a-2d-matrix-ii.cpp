class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            int start = 0;
            int end = matrix[0].size() - 1;
            int mid = start + (end - start)/2;
            while(start <= end){
                int element = matrix[i][mid];
                if(element == target) return true;
                if(element < target) start = mid + 1;
                else end = mid - 1;
                mid = start + (end - start)/2;
            }
        }
        return false;
    }
};