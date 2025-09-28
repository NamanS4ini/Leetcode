class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxPara = 0;
        for (int i = nums.size() - 1; i >= 2; i--) {
            int s1 = nums[i];
            int s2 = nums[i-1];
            int s3 = nums[i-2];
            if (s1 + s2 > s3 && s2 + s3 > s1 && s1 + s3 > s2) {
                maxPara = max(maxPara, s1 + s2 + s3);
            }
        }
        return maxPara;
    }
};