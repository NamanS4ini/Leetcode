class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int j = i == 0 ? j = nums.size() - 1 : i-1;
            if(nums[j] >= nums[i])
                return nums[i];
        }
        return 0;
    }
};