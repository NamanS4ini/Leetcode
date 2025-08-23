class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < heights.size(); i++){
            if(s.empty() || heights[i] > s.top().second){
                s.push({i, heights[i]});
            }
            else{
                int start = i;
                while(!s.empty() && s.top().second > heights[i]){
                    start = s.top().first;
                    int area = (i - start) * s.top().second;
                    maxArea = max(maxArea, area);
                    s.pop();
                }
                s.push({start, heights[i]});
            }
        }
        while(!s.empty()){
            int area = (heights.size() - s.top().first) * s.top().second;
            maxArea = max(maxArea, area);
            s.pop();
        }
        return maxArea;
    }
};