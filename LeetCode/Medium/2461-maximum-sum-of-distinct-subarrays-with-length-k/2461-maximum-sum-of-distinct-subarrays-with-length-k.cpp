class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        long long sum = 0;
        unordered_set<long long> seen;
        long long maxSum = 0;
        while (right < nums.size()) {
            if(seen.find(nums[right]) == seen.end()){
                seen.insert(nums[right]);
                sum += nums[right];
                if(right - left + 1 == k){
                    maxSum = max(maxSum, sum);
                    sum -= nums[left];
                    seen.erase(nums[left++]);
                }
                right++;
            }
            else{
                sum -= nums[left];
                seen.erase(nums[left++]);
            }
        }
        return maxSum;
    }
};