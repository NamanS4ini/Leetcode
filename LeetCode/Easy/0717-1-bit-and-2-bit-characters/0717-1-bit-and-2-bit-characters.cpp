class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int right = 0;
        while(right < bits.size()){
            if(right == bits.size() - 1 && bits[right] == 0)
                return true;
            else if(bits[right] == 0)
                right++;
            else
                right+=2;
        }
        return false;
    }
};