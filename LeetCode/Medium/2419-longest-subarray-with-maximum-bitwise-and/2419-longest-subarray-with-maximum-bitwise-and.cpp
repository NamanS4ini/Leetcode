class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0;
        for(int i: nums){
            maxValue = max(maxValue, i);
        }
        int length = 0;
        int maxLength = 0;
        for(int num: nums){
            if(num == maxValue){
                length++;
                maxLength = max(length, maxLength);
            }
            else{
                length = 0;
            }
        }
        return maxLength;

    }
};