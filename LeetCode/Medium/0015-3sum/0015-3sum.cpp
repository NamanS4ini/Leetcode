class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left - 1] && left < right)
                        left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};