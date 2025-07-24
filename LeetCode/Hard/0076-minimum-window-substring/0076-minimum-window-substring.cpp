class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        int need = 0;
        for (char c : t) {
            if (freq[c] == 0) {
                need++;
            }
            freq[c]++;
        }
        int left = 0;
        int right = 0;
        string minString;
        int minStringLen = INT_MAX;
        int have = 0;
        unordered_map<char, int> seen;
        while (right < s.length()) {
            if (freq[s[right]] > 0) {
                seen[s[right]]++;
                if (seen[s[right]] == freq[s[right]]) {
                    have++;
                }
                if (have == need) {
                    while (have == need) {
                        if (seen[s[left]] == 0) {
                            left++;
                        } else if (seen[s[left]] > 0) {
                            if (seen[s[left]] == freq[s[left]]) {
                                have--;
                            }
                            seen[s[left]]--;
                            left++;
                        }
                    }
                    if (minStringLen > right - left + 1) {
                        minString = s.substr(left - 1, right - left + 2);
                        minStringLen = right - left + 1;
                    }
                }
            }
            right++;
        }
        return minString;
    }
};