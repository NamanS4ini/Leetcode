class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        long long zeroes = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                right++;
            }
            else{
                long long n = right - left;
                zeroes += (n*(n+1))/2;
                right++; left = right;
            }
        }
        long long n = right - left;
        zeroes += (n*(n+1))/2;
        return zeroes;
    }
};