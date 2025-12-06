class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(char c: s)
            freq[c]++;
        int maxOdd = 0;
        int minEven = INT_MAX;
        for(auto& p: freq){
            if(p.second % 2 == 0)
                minEven = min(minEven, p.second);
            else{
                maxOdd = max(maxOdd, p.second);
            }
        }
        return maxOdd - (minEven == INT_MAX?0:minEven);
    }
};