class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        unordered_map<char, int> wrong;
        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                secret.erase(i,1);
                guess.erase(i,1);
                i--;
            }
            else{
                wrong[guess[i]]++;
            }
        }
        int cows = 0;
        // cout << secret << " " << guess;
        for(int i = 0; i < secret.length(); i++){
            if(wrong.find(secret[i]) != wrong.end() && wrong[secret[i]] > 0){
                cout << secret[i] << endl;
                cows++;
                wrong[secret[i]]--;
            }
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};