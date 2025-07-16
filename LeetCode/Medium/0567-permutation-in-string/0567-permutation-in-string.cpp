class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.length();
        if (s1.length() > s2.length())
            return false;
        unordered_map<char, int> s1Freq;
        unordered_map<char, int> s2Freq;
        for (char c : s1) {
            s1Freq[c]++;
        }
        for (char c : s2) {
            s2Freq[c]++;
        }
        if(s1Freq == s2Freq){
            return true;
        }
        unordered_map<char, int> purmFreq;
        for (int i = 0; i < s2.length(); i++) {
            purmFreq[s2[i]]++;
            if (i >= len - 1) {
                if (i - len >= 0) {
                    purmFreq[s2[i - len]]--;
                    if (purmFreq[s2[i - len]] == 0) {
                        purmFreq.erase(s2[i - len]);
                    }
                }
                int match = 0;
                for (auto c : purmFreq) {
                    if (c.second == s1Freq[c.first]) {
                        match+= c.second;
                    }
                }
                cout << match;
                if (match == len) {
                    return true;
                }
            }
        }
        return false;
    }
};