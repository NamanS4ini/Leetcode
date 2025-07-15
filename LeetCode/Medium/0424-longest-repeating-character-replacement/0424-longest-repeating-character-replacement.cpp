class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLen = 1;
            unordered_map<char, int> freq;
            freq[s[0]]++;
        while(right < s.length()){
            int maxFreq = 0;
            for(auto c: freq){
                if(c.second > maxFreq){
                    maxFreq = c.second;
                }
            }
            int replacement = (right - left + 1) - maxFreq;
            if(replacement <= k){
                maxLen = max(maxLen, right - left + 1);
                right++;
                freq[s[right]]++;
            }
            else{
                freq[s[left]]--;
                left++;
            }
        }
        return maxLen;

    }
};