class Solution {
public:
    int countPartitions(std::vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0 );
        if(totalSum%2==0) return nums.size()-1;
        return 0;
    }
};