class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<vector<int>> s;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && s.top()[1] < temperatures[i]) {
                vector<int> top = s.top();
                s.pop();
                ans[top[0]] = i - top[0];
            }
            s.push({i, temperatures[i]});
        }
        return ans;
    }
};