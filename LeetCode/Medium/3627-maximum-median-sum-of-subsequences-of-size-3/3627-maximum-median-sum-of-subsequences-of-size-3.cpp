class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int i = 0; i < nums.size() / 3; i++){
            sum += nums[nums.size() - 2 -(i*2)];
        }
        return sum;
    }
};