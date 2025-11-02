class Solution {
    void solve(int i, vector<vector<int>>& ans, vector<int>& nums,
               vector<int>& curr) {
        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        solve(i + 1, ans, nums, curr);
        curr.push_back(nums[i]);
        solve(i + 1, ans, nums, curr);
        curr.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, ans, nums, curr);
        return ans;
    }
};