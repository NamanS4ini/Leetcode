class Solution {
public:
    void solve(vector<string>& ans, string& output, vector<string> map, string digits, int index){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        for(int i = 0; i < map[number].length(); i++){
            output += map[number][i];
            solve(ans, output, map, digits, index+1);
            output.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(!digits.length())
            return {};
        vector<string> ans;
        string output;
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(ans, output, map, digits, 0);
        return ans;
    }
};