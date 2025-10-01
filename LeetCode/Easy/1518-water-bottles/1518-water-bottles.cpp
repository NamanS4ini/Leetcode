class Solution {
public:
    int numWaterBottles(int n, int a) {
        return n + ((n-1)/(a-1));
    }
};