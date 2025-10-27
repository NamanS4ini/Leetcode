class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
        freq[0]++;
        int prefix = 0;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int diff = prefix - k;
            total += freq[diff];
            freq[prefix]++;
        }
        return total;
    }
};