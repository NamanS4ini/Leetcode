class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack <pair<int, int>> s;
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
};