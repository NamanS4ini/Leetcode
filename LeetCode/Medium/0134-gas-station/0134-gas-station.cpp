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
        int fuel = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                fuel = 0;
                start = i + 1 >= gas.size() ? 0 : i + 1;
            }
        }
        return start;
    }
};