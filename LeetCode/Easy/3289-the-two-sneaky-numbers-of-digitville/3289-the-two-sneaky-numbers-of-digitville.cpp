class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> sneaky;
        for(int num: nums){
            if(set.find(num) != set.end())
                sneaky.push_back(num);
            set.insert(num);
        }
        return sneaky;
    }
};