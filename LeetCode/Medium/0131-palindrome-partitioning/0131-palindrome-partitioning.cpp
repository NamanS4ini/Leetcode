class Solution {
    bool checkPalindrome(string s){
        string d = s;
        reverse(s.begin(), s.end());
        return s == d;
    }
    void solve(string& s, vector<vector<string>>& ans, vector<string>& out, int idx){
        if(idx >= s.size()){
            ans.push_back(out);
            return;
        }
        string toPush;
        for(int i = idx; i < s.size(); i++){
            toPush.push_back(s[i]);
            if(checkPalindrome(toPush)){
                out.push_back(toPush);
                solve(s, ans, out, i+1);
                out.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> out;
        solve(s, ans, out, 0);
        return ans;
    }
};