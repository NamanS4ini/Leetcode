class Solution {
    int count = 0;
    void solve(vector<int>& nums, int idx, int target) {
        if(idx >= nums.size())
            return;
        int lc = 0;
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] == target)
                lc++;
            if(lc > (i - idx + 1)/2)
                count++;
        }
        solve(nums,  idx+1, target);
    }
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> curr;
        solve(nums, 0, target);
        return count;
    }
};