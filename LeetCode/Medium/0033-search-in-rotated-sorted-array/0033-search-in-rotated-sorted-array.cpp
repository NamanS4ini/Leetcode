class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int startIdx = -1;
        while(high >= low){
            int mid = (low + high)/2;
            int right = (mid + 1) % nums.size();
            if(nums[mid] > nums[right]){
                startIdx = mid + 1;
                break;    
            }
            if(nums[mid] < nums[nums.size() - 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        startIdx = startIdx == -1 ? 0 : startIdx;
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