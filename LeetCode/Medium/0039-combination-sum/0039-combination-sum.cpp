class Solution {
    void solve(vector<int>& candidates, int& target, vector<vector<int>>& ans, vector<int> output, int sum, int idx){
        if(sum == target){
            ans.push_back(output);
            return;
        }
        if(sum > target){
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            sum += candidates[i];
            output.push_back(candidates[i]);
            solve(candidates, target, ans, output, sum, i);
            output.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, ans, output, 0, 0);
        return ans;
    }
};