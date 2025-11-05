class Solution {
    void solve(vector<int>& candidates, int& target, vector<vector<int>>& ans, vector<int> output, int sum, int idx){
        if(sum == target){
            if(find(ans.begin(), ans.end(), output) == ans.end())
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
        for(int i = 0; i < candidates.size(); i++)
            solve(candidates, target, ans, output, 0, i);
        return ans;
    }
};