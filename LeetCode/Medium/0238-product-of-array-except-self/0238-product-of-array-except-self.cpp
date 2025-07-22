class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i];
        }

        vector<int> suffix(nums.size(), 1);
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i];
        }
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            int prefVal = i - 1 >= 0 ? prefix[i-1] : 1;
            int suffVal = i + 1 < nums.size()? suffix[i+1] : 1;
            ans[i] = prefVal * suffVal;
        }
        return ans;
    }
};