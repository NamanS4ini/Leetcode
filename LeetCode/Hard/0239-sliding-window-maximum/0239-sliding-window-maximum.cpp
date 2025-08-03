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
                freq[nums[right]]++;
                maxNum = max(maxNum, nums[right]);
                if(freq[maxNum] == 0){
                    maxNum = INT_MIN;
                    for(int i = left; i <= right; i++){
                        maxNum = max(maxNum, nums[i]);
                    }
                }
                ans.push_back(maxNum);
                freq[nums[left++]]--;
                    right++;

            }
        }
        return ans;
    }
}; 