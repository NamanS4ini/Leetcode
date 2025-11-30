class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int miss = k;
            if(find(nums.begin(), nums.end(), miss) == nums.end())
                return miss;
        for(int num: nums){
            miss += k;
            if(find(nums.begin(), nums.end(), miss) == nums.end())
                return miss;
        }
        return miss;
    }
};