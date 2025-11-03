class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0;
        int right = 1;
        int minTime = 0;
        while(right < colors.length()){
            if(colors[left] == colors[right]){
                if(neededTime[left] < neededTime[right]){
                    minTime += neededTime[left];
                    left = right;
                    right++;
                }
                else{
                    minTime += neededTime[right];
                    right++;
                }
            }
            else{
                left = right;
                right++;
            }
        }
        return minTime;
    }
};