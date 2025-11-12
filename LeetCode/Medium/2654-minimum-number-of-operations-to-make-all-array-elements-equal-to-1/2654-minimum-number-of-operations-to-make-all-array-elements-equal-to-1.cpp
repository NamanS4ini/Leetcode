class Solution {
public:
    int minOperations(vector<int>& nums) {
        int oneGCD = nums[0];
        int one = 0;
        for (int n : nums) {
            if(n == 1){
                one++;
            }
            oneGCD = gcd(oneGCD, n);
        }
        if(one > 0){
            return nums.size() - one;
        }
        if (oneGCD != 1)
            return -1;
        int minLen = INT_MAX;
        int subGCD = nums[0];
        int left = 0;
        int right;
        for (right = 1; right < nums.size(); right++) {
            subGCD = gcd(subGCD, nums[right]);
            if (subGCD == 1) {
                while (left + 1 <= right && subGCD == 1) {
                    left++;
                    subGCD = nums[left];
                    for (int i = left + 1; i <= right; i++) {
                        subGCD = gcd(subGCD, nums[i]);
                    }
                }
                minLen = min(minLen, right - left);
            }
        }
        int count = minLen + nums.size();
        return count;
    }
};