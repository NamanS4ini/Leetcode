class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int idx){
        if(idx >= nums.size()){
            if(find(ans.begin(), ans.end(), output) == ans.end())
                ans.push_back(output);
            return;
        }
        solve(nums, ans, output, idx + 1);
        output.push_back(nums[idx]);
        solve(nums, ans, output, idx + 1);
        output.pop_back();
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