class Solution {
    void solve(vector<int>& nums, set<vector<int>>& ans, int idx){
        if(idx >= nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            solve(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums, ans, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};