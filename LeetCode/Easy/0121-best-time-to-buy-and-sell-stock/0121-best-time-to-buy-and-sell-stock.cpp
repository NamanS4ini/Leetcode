class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int profit = 0;
        while(right < prices.size()){
            if(prices[left] > prices[right]){
                left = right;
                right++;
            }
            else{
                int currProf = prices[right] - prices[left];
                profit = max(profit, currProf);
                right++;
            }
        }
        return profit;
    }
};