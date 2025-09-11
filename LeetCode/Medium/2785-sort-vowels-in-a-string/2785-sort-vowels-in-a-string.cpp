class Solution {
public:
    string sortVowels(string s) {
        vector<int> pos;
        vector<char> vow;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')){
                    pos.push_back(i);
                    vow.push_back(ch);
                }
        }
        sort(pos.begin(), pos.end());
        sort(vow.begin(), vow.end());
        for(int i = 0; i < pos.size(); i++){
            s[pos[i]] = vow[i];
        }
        return s;
    }
};