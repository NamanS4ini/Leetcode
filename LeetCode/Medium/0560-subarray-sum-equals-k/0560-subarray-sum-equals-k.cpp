class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int diff = sum - k;
            count += sums[diff];
            sums[sum]++;
        }
        return count;
    }
};