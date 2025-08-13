class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        for(int i = 0; i < n; i++){
            if(pow(3,i) == n){
                return true;
            }
            else if(pow(3,i) > n){
                return false;
            }
        }
        return false;
    }
};