class Solution {
public:
    void solve(vector<string> mapping, vector<string>& ans, string output,
               string digits, int index) {
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mapping[digit];
        for (int j = 0; j < letters.size(); j++) {
            output.push_back(letters[j]);
            solve(mapping, ans, output, digits, index + 1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() <= 0) {
            return {};
        }
        vector<string> ans;
        string output;
        vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(mapping, ans, output, digits, 0);
        return ans;
    }
};