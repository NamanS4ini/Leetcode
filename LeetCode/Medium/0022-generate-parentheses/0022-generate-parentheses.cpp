class Solution {
public:
    bool isValid(string output) {
        stack<char> s;
        for (char c : output) {
            if (c == '(') {
                s.push(c);
            } else {
                if (s.empty()) {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
    void solve(vector<string>& ans, string output, int n) {
        if (output.length() >= n * 2) {
            if (isValid(output))
                ans.push_back(output);
            return;
        }
        output += ")";
        solve(ans, output, n);
        output.pop_back();
        output += "(";
        solve(ans, output, n);
        output.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "(";
        solve(ans, output, n);
        return ans;
    }
};