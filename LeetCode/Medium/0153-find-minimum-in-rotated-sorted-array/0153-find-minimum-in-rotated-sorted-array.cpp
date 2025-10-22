class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            int left = mid == 0 ? nums.size() - 1 : mid - 1;
            int right = mid == nums.size() - 1 ? 0 : mid + 1;
            // if (nums[left] > nums[mid])
            //     return nums[mid];
            if (nums[mid] > nums[right])
                return nums[mid + 1];
            if (nums[mid] > nums[nums.size() - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[0];
    }
};