class Solution {
public:
    int totalMoney(int n) {
        int prev = 0;
        int total = 0;
        while(n > 0){
            int curr = ++prev;
            int currtotal = 0;
            int times = n > 7 ? 7 : n;
            for(int i = 0; i < times; i++){
                currtotal += curr++;
            }
            n -= 7;
            total += currtotal;
        }
        return total;
    }
};