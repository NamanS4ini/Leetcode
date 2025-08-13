class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int swaps = 0;
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(s[left] == '[')
                st.push('[');
            else{
                if(!st.empty())
                    st.pop();
                else{
                    while(s[right] != '['){
                        right--;
                    }
                    swaps++;
                    right--;
                    st.push('[');
                }
            }
            left++;
        }
        return swaps;
    }
};