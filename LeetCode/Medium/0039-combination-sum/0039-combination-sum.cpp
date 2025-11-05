class Solution {
    void solve(vector<int>& candidates, int& target, vector<vector<int>>& ans, vector<int> output, int sum, int i){
        if(sum == target){
            ans.push_back(output);
            return;
        }
        if(sum > target || i >= candidates.size()){
            return;
        }
        sum += candidates[i];
        output.push_back(candidates[i]);
        solve(candidates, target, ans, output, sum, i);
        output.pop_back();
        sum -= candidates[i];
        solve(candidates, target, ans, output, sum, i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, ans, output, 0, 0);
        return ans;
    }
};