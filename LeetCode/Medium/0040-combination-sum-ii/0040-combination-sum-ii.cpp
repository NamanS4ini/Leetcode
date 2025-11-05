class Solution {
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& output, int sum, int idx){
        if(sum == target){
            ans.push_back(output);
            return;
        }
        if(sum > target)
            return;
        for(int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            output.push_back(candidates[i]);
            solve(candidates, target, ans, output, sum, i+1);
            output.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ans, output, 0, 0);
        return ans;
    }
};