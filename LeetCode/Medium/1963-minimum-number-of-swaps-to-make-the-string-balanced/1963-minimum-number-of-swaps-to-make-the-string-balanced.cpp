class Solution {
public:
    int minSwaps(string s) {
        int close = 0;
        int open = 0;
        int swaps = 0;
        int right = s.length() - 1;
        for(int i = 0; i < right; i++){
            char c = s[i];
            if(c == '['){
                open++;
            }
            else{
                if(close + 1 <= open){
                    close++;
                }
                else{
                    while(s[right] != '['){
                        right--;
                    }
                    right--;
                    swaps++;
                }
            }
        }
        return ceil(swaps/2.0);
    }
};