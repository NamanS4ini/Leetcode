class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int maxSum = sum;
        for(int i = k; i < size; i++){
            sum -= nums[i-k];
            sum += nums[i];
            maxSum = max(sum, maxSum);
        }
        return double(maxSum)/k;
    }
};