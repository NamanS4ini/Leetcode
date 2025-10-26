class Solution {
    
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int upperBound = 99999;
        int lowerBound = -99999;
        int currUB = INT_MIN;
        int currLB = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            vector<int> v = nums[i];
            minHeap.push({v[0],i,0});
            currUB = max(currUB, v[0]);
        }

        while(minHeap.size()){
            vector<int> curr = minHeap.top();
            minHeap.pop();
            currLB = curr[0];
            int currIdx = curr[2];
            int listIdx = curr[1];
            if(currUB - currLB < upperBound - lowerBound){
                upperBound = currUB;
                lowerBound = currLB;
            }
            if(currIdx + 1 < nums[listIdx].size()){
                minHeap.push({nums[listIdx][currIdx+1], listIdx, currIdx + 1});
                currUB = max(currUB, nums[listIdx][currIdx+1]);
            }
            else{
                break;
            }
        }
        return {lowerBound, upperBound};
    }
};