class Solution {
    const int MOD = 1e9 + 7;
public:
    int numSub(string s) {
        long long total = 0;
        long long curr = 0;
        for(char c: s){
            if(c == '0'){
                total = (total + curr* (curr+1)/2) % MOD;
                curr = 0;
            }
            else{
                curr++;
            }
        }
        total = (total + curr* (curr+1)/2) % MOD;
        return total;
    }
};