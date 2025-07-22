class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        unordered_map<char, int> freq;
        while(right < s.length()){
            freq[s[right]]++;
            int maxFreq = 0;
            for(auto c: freq){
                maxFreq = max(maxFreq, c.second);
            }
            int length = right - left + 1;
            int replacements = length - maxFreq;
            if(replacements > k){
                freq[s[left++]]--;
                length--;
            }
            maxLength = max(maxLength, length);
            right++;
        }
        return maxLength;
    }
};