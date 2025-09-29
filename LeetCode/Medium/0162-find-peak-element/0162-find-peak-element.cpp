class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid = nums.size()/2;
        while( mid < 0 || mid < nums.size()){
            int prev = mid == 0 ? INT_MIN : nums[mid - 1];
            int next = mid == nums.size() - 1 ? INT_MIN : nums[mid + 1];
            if(nums[mid] > prev && nums[mid] > next)
                return mid;
            else{
                mid = nums[mid] < prev ? mid - 1 : mid + 1;
            }
        }
        return 0;
    }
};