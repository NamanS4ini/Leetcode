class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        vector<int> ans;
        unordered_map<int, int> freq;
        int maxNum = INT_MIN;
        while(right < nums.size()){
            if(right - left + 1 != k){
                maxNum = max(maxNum, nums[right]);
                freq[nums[right]]++;
                right++;
            }
            else{
                maxNum = max(maxNum, nums[right]);
                freq[nums[left]]--;
                freq[nums[right]]++;
                ans.push_back(maxNum);
                if(nums[left] == maxNum && freq[nums[left]] == 0){
                    maxNum = INT_MIN;
                    for(int i = left+1; i <= right; i++){
                        maxNum = max(maxNum, nums[i]);
                    }
                }
                left++;
                right++;
            }
        }
        return ans;
    }
};