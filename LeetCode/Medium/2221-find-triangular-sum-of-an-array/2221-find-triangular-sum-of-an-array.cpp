class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> newNums;
        while (nums.size() > 1) {
            for (int i = 0; i < nums.size() - 1; i++) {
                int num = nums[i];
                int next = nums[i + 1];
                newNums.push_back((num + next) % 10);
            }
            nums = newNums;
            newNums = {};
        }
        return nums[0];
    }
};