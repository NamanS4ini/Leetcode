class Solution {
private:
    int findHistMaxArea(vector<int> heights) {
        int maxArea = 0;
        stack<pair<int, int>> s;
        for (int i = 0; i < heights.size(); i++) {
            int element = heights[i];
            int startIndex = i;
            while (!s.empty() && s.top().second > element) {
                startIndex = s.top().first;
                maxArea = max(maxArea, (i - s.top().first) * s.top().second);
                s.pop();
            }
            s.push({startIndex, element});
        }
        while (!s.empty()) {
            int currArea = (heights.size() - s.top().first) * s.top().second;
            maxArea = max(maxArea, currArea);
            s.pop();
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size(),0);
        int maxArea = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    histogram[j] = 0;
                }
                else{
                    histogram[j] += (matrix[i][j] - '0');
                }
            }
            maxArea = max(maxArea, findHistMaxArea(histogram));
        }
        return maxArea;
    }
};