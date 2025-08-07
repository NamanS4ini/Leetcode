class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<pair<int,int>> stack;
        for(int j = 0; j < nums.size() * 2; j++){
            int i = j >= nums.size() ? j - nums.size() : j;
            while(!stack.empty() && nums[i] > stack.top().second){
                ans[stack.top().first] = nums[i];
                stack.pop();
            }
            stack.push({i, nums[i]});
        }
        return ans;
    }
};