class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int maxCount = 0;
        while (right < nums.size()) {
            if(nums[right] == nums[left]){
                right++;
            }
            else if (nums[right] - nums[left] == 1) {
                right++;
                maxCount = max(maxCount, right - left);
            } else {
                left++;
            }
        }

        return maxCount;
    }
};