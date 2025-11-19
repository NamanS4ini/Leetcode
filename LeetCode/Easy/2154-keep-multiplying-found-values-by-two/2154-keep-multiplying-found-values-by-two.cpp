class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> num;
        for(int n: nums)
            num.insert(n);
        while(num.find(original) != num.end())
            original *= 2;
        return original;
    }
};