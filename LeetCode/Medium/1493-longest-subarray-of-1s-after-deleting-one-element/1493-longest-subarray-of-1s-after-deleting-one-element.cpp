class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxSub = 0;
        int left = 0;
        unordered_map<int, int> freq;
        int right = 0;
        while (right < nums.size()) {
            int val = nums[right];
            freq[val]++;
            if (freq[0] > 1 && left < right) {
                while (freq[0] > 1) {
                    freq[nums[left]]--;
                    left++;
                }
                right++;
                if (left > right) {
                    right = left;
                }
            } else {
                maxSub = max(maxSub, freq[1]);
                right++;
            }
        }
        return maxSub == nums.size() ? maxSub - 1: maxSub;
    }
};