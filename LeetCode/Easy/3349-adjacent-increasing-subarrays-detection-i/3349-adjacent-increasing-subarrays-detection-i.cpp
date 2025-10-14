class Solution {
public:
bool checkInc(vector<int> nums, int start, int end){
    for(int i = start; i < end; i++){
        if(i+1 >= nums.size() || nums[i] >= nums[i+1])
            return false;
    }
    return true;
}
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            if(checkInc(nums, i, i + k - 1) && checkInc(nums, i + k, i + 2*k - 1))
                return true;
        }
        return false;
    }
};