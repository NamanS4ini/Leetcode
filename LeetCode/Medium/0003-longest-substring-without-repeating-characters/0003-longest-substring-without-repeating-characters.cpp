class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxSize = 0;
        unordered_set<char> set;
        while(right < s.length()){
            if(set.find(s[right]) == set.end()){
                set.insert(s[right]);
                right++;
                maxSize = max(maxSize, right-left);
            }
            else{
                set.erase(s[left++]);
            }
        }

        return maxSize;
    }
};