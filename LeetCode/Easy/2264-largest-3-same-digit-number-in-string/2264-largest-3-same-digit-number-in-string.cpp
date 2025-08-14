class Solution {
public:
    string largestGoodInteger(string num) {
        string maxGood = "";
        for(int i = 0; i <= num.length() - 3; i++){
            string s = num.substr(i,3);
            bool isGood = true;
            for(int j = 0; j < 2; j++){
                if(s[j] != s[j+1]){
                    isGood = false;
                }
            }
            if(!isGood){
                continue;
            }
            if(maxGood == "" || stoi(maxGood) < stoi(s)){
                maxGood = s;
            }
        }
        return maxGood;
    }
};