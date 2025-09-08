class Solution {
public:
    bool check(int i){
        string s = to_string(i);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0')
                return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            int j = n - i;
            if(check(i) && check(j)){
                    return {i,j};
            }
        }
        return {};
    }
};