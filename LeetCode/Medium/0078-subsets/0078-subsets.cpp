class Solution {
    void solve(int& i, vector<vector<int>>& ans, vector<int>& nums,
               vector<int>& curr) {
        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        i++;
        solve(i, ans, nums, curr);
        i--;
        curr.push_back(nums[i]);
        i++;
        solve(i, ans, nums, curr);
        i--;
        curr.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index = 0;
        solve(index, ans, nums, curr);
        return ans;
    }
};