class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxSub = 0;
        int left = 0;
        int zeroes = 0;
        int right = 0;
        while (right < nums.size()) {
            if(nums[right] == 0)
                zeroes++;
            if(zeroes > 1){
                while(zeroes > 1){
                    if(nums[left] == 0)
                        zeroes--;
                    left++;
                }
            }
            maxSub = max(maxSub, right - left + 1 - zeroes);
            right++;
        }
        return maxSub == nums.size() ? maxSub - 1: maxSub;
    }
};