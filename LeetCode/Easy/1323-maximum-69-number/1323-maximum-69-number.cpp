class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for(int i = 0; i < n.size(); i++){
            if(n[i] == '6'){
                n.replace(i,1,"9");
                break;
            }
        }
        return stoi(n);
    }
};