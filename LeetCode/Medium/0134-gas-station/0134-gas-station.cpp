class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) {
            return -1;
        }
        int index = 0;
        int remainingGas = 0;
        for(int i = 0; i < gas.size(); i++){
            remainingGas += gas[i] - cost[i];
            if(remainingGas >= 0 && index == -1){
                index = i;
            }
            if(remainingGas < 0){
                remainingGas = 0;
                index = -1;
            }
        }
        return index;
    }
};