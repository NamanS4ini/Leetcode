class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_map <char, int> freq;
        int maxLength = 0;
        freq[s[0]]++;
        while(right < s.length()){
            int maxFreq = 0;
            for(auto f: freq){
                maxFreq = max(maxFreq, f.second);
            }
            int length = right - left + 1;
            int replacement = length - maxFreq;
            if(replacement <= k){
                maxLength = max(maxLength, right - left + 1);
                right++;
                freq[s[right]]++;
            }
            else{
                freq[s[left++]]--;
            }
        }
        return maxLength;
    }
};