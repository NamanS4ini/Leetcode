class Solution {
public:
    bool duplicate(vector<int> output){
        for(int i = 0; i < output.size() - 1; i++){
            for(int j = i + 1; j < output.size(); j++){
                if(output[i] == output[j]){
                    return true;
                }
            }
        }
        return false;
    }
    void solve(vector<int> nums, vector<vector<int>>& ans, vector<int> output, int index){
        if(index >= nums.size()){
            if(nums.size() == output.size() && !duplicate(output))
                ans.push_back(output);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            output.push_back(nums[i]);
            solve(nums, ans, output,index+1);
            output.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, ans, output,index);
        return ans;
    }
};