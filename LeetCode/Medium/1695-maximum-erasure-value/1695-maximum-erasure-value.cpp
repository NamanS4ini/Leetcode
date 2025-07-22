class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0;
        int left = 0;
        int right = 0;
        unordered_set<int> seen;
        int currSum = 0;
        while(right < nums.size()){
            int value = nums[right];
            if(seen.find(value) == seen.end()){
                currSum += value;
                maxSum = max(maxSum, currSum);
                seen.insert(value);
                right++;
            }
            else{
                currSum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
        }
        return maxSum;
    }
};