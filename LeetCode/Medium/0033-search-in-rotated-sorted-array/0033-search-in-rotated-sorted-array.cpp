class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(high > low){
            int mid = (high + low)/2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        int startIdx = low;
        low = 0;
        high = nums.size() - 1;
        while(low <= high){
            int mid = ((low + high)/2 + startIdx) % nums.size();
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                low = (low + high)/2 + 1;
            else
                high = (low + high)/2 - 1;
        }
        return -1;
    }
};