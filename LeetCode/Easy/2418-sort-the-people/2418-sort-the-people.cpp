class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i = 0; i < names.size()-1; i++){
            int maxIndex = i;
            for(int j = i+1; j < names.size(); j++){
                if(heights[maxIndex] < heights[j]){
                    maxIndex = j;
                }
            }
            swap(heights[maxIndex],heights[i]);
            swap(names[maxIndex],names[i]);
        }
        return names;
    }
};