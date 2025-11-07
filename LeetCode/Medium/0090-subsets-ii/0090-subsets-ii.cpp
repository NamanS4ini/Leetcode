class Solution {
    void solve(vector<int>& nums, set<vector<int>>& ans, vector<int>& output, int idx){
        if(idx >= nums.size()){
            ans.insert(output);
            return;
        }
        solve(nums, ans, output, idx + 1);
        if(idx == 0 || nums[idx] != nums[idx-1] || (output.size() && output[output.size()-1] == nums[idx])){
            output.push_back(nums[idx]);
            solve(nums, ans, output, idx + 1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        solve(nums, ans, output, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
}; 