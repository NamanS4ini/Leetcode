class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        set<int> s;
        for(int num : nums){
            s.insert(num);
        }
        int allTimeLong = 1;
        int current = 1;
        for(int num: s){
            if(s.count(num - 1)){
                current++;
                allTimeLong = max(current, allTimeLong);
            }
            else{
                current = 1;
            }
        }
        return allTimeLong;
    }
};