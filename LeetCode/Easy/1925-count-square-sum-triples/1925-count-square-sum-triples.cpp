class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    if(pow(a,2) + pow(b,2) == pow(c,2))
                        count++;
                }
            }
        }
        return count;
    }
};