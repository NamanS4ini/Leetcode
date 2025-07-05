class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> count(501);
        for(int i = 0; i < arr.size(); i++){
            count[arr[i]]++;
        }

        for(int i = count.size()-1; i > 0; i--){
            if(count[i] == i) return i;
        }
        return -1;
    }
};