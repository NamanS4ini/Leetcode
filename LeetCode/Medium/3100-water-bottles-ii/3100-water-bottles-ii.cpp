class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        int emptyBottles = 0;
        while(numBottles >= numExchange){
            int newTotal = total;
            while(numBottles >= numExchange){
                newTotal++;
                numBottles -= numExchange;
                numExchange++;
            }
            numBottles += newTotal - total;
            total = newTotal;
        }
        return total;
    }
};