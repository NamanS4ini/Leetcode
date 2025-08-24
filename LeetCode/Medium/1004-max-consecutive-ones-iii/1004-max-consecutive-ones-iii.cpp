class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxSub = 0;
        int left = 0;
        int zeroes = 0;
        int right = 0;
        while (right < nums.size()) {
            if(nums[right] == 0)
                zeroes++;
            if(zeroes > k){
                while(zeroes > k){
                    if(nums[left] == 0)
                        zeroes--;
                    left++;
                }
            }
            maxSub = max(maxSub, right - left + 1);
            right++;
        }
        return maxSub;
    }
};