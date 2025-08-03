class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int shipment = 0;
        for(int i = 0; i < weight.size() - 1; i++){
            if(weight[i] > weight[i+1]){
                shipment++;
                i++;
            }
        }
        return shipment;
    }
};