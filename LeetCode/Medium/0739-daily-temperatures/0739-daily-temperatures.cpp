class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<vector<int>> s;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top()[1] <= temperatures[i]) {
                s.pop();
            }
            if (!s.empty())
                ans[i] = s.top()[0] - i;
            s.push({i, temperatures[i]});
        }
        return ans;
    }
};