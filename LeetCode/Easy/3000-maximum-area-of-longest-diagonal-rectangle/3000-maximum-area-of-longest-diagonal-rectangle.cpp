class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float maxDiagonal = 0;
        int maxArea = 0;
        for(vector<int> rect: dimensions){
            float diagonal = sqrt(rect[0] * rect[0] + rect[1] * rect[1]);
            cout << diagonal << " ";
            if(maxDiagonal < diagonal){
                maxDiagonal = diagonal;
                maxArea = rect[0] * rect[1];
            }
            if(maxDiagonal == diagonal){
                maxArea = max(maxArea, rect[0] * rect[1]);
            }
        }
        return maxArea;
    }
};