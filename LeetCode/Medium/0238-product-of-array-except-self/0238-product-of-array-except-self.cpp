class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            prefix[i] = nums[i] * prefix[i - 1];
        vector<int> suffix(nums.size());
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix[i] = nums[i] * suffix[i+1];
        }

        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int pre = i > 0 ? prefix[i-1] : 1;
            int suff = i < nums.size() - 1 ? suffix[i+1] : 1;
            ans[i] = pre*suff;
        }
        return ans;
    }
};