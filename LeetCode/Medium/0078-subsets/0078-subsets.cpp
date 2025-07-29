class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>>& ans, vector<int> output, int index, int size){
        if(index >= size){
            ans.push_back(output);
            return;
        }
        solve(nums, ans, output, index+1, size);
        output.push_back(nums[index]);
        solve(nums, ans, output, index+1, size);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        int size = nums.size();
        solve(nums, ans, output, index, size);
        return ans;
    }
};