class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxFreq = 0;
        for(int num: nums){
            m[num]++;
            maxFreq = max(maxFreq, m[num]);
        }
        int ans = 0;
        for(auto i : m){
            if(i.second == maxFreq){
                ans+= i.second;
            }
        }
        return ans;
    }
};