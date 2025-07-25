class Solution {
public:
    void solve(vector<int> nums, vector<int> output, vector<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        // exclude
        solve(nums,output,ans,index+1);
        // include
        output.push_back(nums[index]);
        solve(nums,output,ans,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, ans, index);
        return ans;
    }
};