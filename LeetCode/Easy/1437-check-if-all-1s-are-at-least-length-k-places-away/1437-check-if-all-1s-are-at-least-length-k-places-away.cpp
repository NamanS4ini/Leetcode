class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dis = nums.size();
        for(int n: nums){
            if(n == 1){
                if(dis < k)
                    return false;
                dis = 0;
            }
            else{
                dis++;
            }
        }
        return true;
    }
};