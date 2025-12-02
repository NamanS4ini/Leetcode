class Solution {
    unordered_map<int, int> seen;
public:
    int tribonacci(int n) {
        if(seen[n]){
            return seen[n];
        }
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        int num = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        seen[n] = num;
        return num;
    }
};