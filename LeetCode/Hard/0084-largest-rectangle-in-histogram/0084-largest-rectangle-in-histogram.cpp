class Solution {
public:
    vector<int> nextSmaller(vector<int> arr, int size) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);
        for (int i = size - 1; i >= 0; i--) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> arr, int size) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);
        for (int i = 0; i < size; i++) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> next(size);
        vector<int> prev(size);
        next = nextSmaller(heights, size);
        prev = prevSmaller(heights, size);
        int maxArea = 0;

        for (int i = 0; i < size; i++) {
            int length = heights[i];
            if (next[i] == -1) {
                next[i] = size;
            }
            int width = next[i] - prev[i] - 1;
            int area = length * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};