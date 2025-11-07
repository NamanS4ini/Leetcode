class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int idx) {
        ans.push_back(output);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            output.push_back(nums[i]);
            solve(nums, ans, output, i + 1);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(nums, ans, output, 0);
        return ans;
    }
};