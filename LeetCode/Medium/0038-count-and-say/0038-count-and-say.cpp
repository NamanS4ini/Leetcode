class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        int count = 1;
        string newS = "";
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1])
                count++;
            else {
                newS.push_back(count + '0');
                newS.push_back(s[i]);
                count = 1;
            }
        }
        newS.push_back(count + '0');
        newS.push_back(s[s.length() - 1]);
        return newS;
    }
};