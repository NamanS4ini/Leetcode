class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int maxSum = 0;
        unordered_set<int> seen;
        int left = 0;
        int right = 0;
        int currSum = 0;
        while (right < nums.size()) {
            if (right - left + 1 < k) {
                if (seen.find(nums[right]) == seen.end()) {
                    seen.insert(nums[right]);
                    currSum += nums[right];
                    right++;
                } else {
                    seen.erase(nums[left]);
                    currSum -= nums[left];
                    left++;
                }
            } else {
                if (seen.find(nums[right]) != seen.end()) {
                    while (seen.find(nums[right]) != seen.end()) {
                        seen.erase(nums[left]);
                        currSum -= nums[left];
                        left++;
                    }
                } else {
                    seen.insert(nums[right]);
                    currSum += nums[right];
                    maxSum = max(maxSum, currSum);
                    seen.erase(nums[left]);
                    currSum -= nums[left];
                    left++;
                    right++;
                }
            }
        }
        return maxSum;
    }
};