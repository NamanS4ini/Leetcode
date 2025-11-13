class Solution {
public:
    int maxOperations(string s) {
        int swaps = 0;
        int ones = 0;
        int zeroes = 0;
        for (char c: s) {
            if(c == '1'){
                swaps += ones * zeroes;
                ones++;
                zeroes = 0;
            }
            else{
                zeroes = 1;
            }
        }

        swaps += ones * zeroes;
        return swaps;
    }
};