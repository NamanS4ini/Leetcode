class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowel;
        unordered_map<char, int> cons;
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowel[c]++;
            else
                cons[c]++;
        }
        int maxVo = 0;
        int maxCo = 0;
        for(auto p: vowel)
            maxVo = max(maxVo, p.second);
        for(auto p: cons)
            maxCo = max(maxCo, p.second);
        return maxVo + maxCo;
    }
};