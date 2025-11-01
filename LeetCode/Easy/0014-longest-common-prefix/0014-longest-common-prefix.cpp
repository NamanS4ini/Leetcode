class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        sort(arr.begin(), arr.end());
        string prefix = "";
        for(int i = 0; i < arr[0].length(); i++){
            bool flag = true;
            for(int j = 1; j < arr.size(); j++){
                if(arr[0][i] != arr[j][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) prefix.push_back(arr[0][i]);
            else break;
        }
        return prefix;
    }
};