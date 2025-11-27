class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        unordered_set<int> seen;
        int left = 0;
        int right = 0;
        long long currSum = 0;
        while (right < nums.size()) {
            if (seen.find(nums[right]) != seen.end()) {
                seen.erase(nums[left]);
                currSum -= nums[left];
                left++;
            } else {
                if (right - left + 1 == k) {
                    seen.insert(nums[right]);
                    currSum += nums[right];
                    maxSum = max(maxSum, currSum);
                    seen.erase(nums[left]);
                    currSum -= nums[left];
                    left++;
                    right++;
                } else{
                    seen.insert(nums[right]);
                    currSum += nums[right];
                    right++;
                }
            }
        }
        return maxSum;
    }
};