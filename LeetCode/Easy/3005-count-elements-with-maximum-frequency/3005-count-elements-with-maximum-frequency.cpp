class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(100,0);
        int maxFreq = 0;
        for(int num: nums){
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        int total = 0;
        for(int p: freq){
            if(p == maxFreq){
                total += p;
            }
        }
        return total;
    }
};