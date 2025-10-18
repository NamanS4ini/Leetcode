class Solution {
public:
    int divide(int dividend, int divisor) {
        if(long(dividend) / long(divisor) < INT_MIN)
            return INT_MIN;
        if(long(dividend) / long(divisor) > INT_MAX)
            return INT_MAX;
        return dividend / divisor;
    }
};