class Solution {
    bool canEat(int eat, vector<int> piles, int h) {
        int time = 0;
        cout << eat << " ";
        for (int pile : piles) {
            int currTime = pile % eat == 0 ? pile / eat : pile / eat + 1;
            time += currTime ? currTime : 1;
            if (time > h)
                return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for (int pile : piles)
            high = max(high, pile);
        int eat = 0;
        while (low <= high) {
            int mid = low - ((low - high) / 2);
            if (canEat(mid, piles, h)) {
                eat = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return eat;
    }
};
// for(int eat = 1; eat < INT_MAX; eat++){
//     int time = 0;
//     for(int pile: piles){
//         int currTime = pile % eat == 0 ? pile/eat : pile/eat + 1;
//         time += currTime ? currTime : 1;
//         if(time > h)
//             break;
//     }
//     if(time <= h){
//         return eat;
//     }
// }
// return 0;