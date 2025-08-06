class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        unordered_map<int, int> seen;
        seen[0]++;
        int ans = 0;
        for(int num: prefix){
            int diff = num - k;
            ans += seen[diff];
            seen[num]++;
        } 
        return ans;
    } 
};