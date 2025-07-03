class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        for(int i = 0; i < k; i++){
            int len = ans.length();
            for(int j = 0; j < len; j++){
                if(ans[j] == 'z'){
                    ans.append("a");
                }
                else{
                    string part(1, char(ans[j]+1));
                    ans.append(part);
                }
            }
            if(ans.length() >= k) break;
        }
        cout << ans;
        return ans[k-1];
    }
};