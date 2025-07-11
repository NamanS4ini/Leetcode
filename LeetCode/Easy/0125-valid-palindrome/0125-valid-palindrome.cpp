class Solution {
public:
    bool isPalindrome(string s) {
    int len = s.length();
    for(int i = 0; i < len; i++){
        if (int(s[i])>64 && int(s[i])< 91)
        {
            s.at(i) = char(int(s[i])+32);
        }
        else if(int(s[i])>96 && int(s[i])< 121){
            continue;
        }
        else{
            s.replace(i, 1, "");
            len = s.length();
            i--;
        }
    }
    cout << s;
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
};