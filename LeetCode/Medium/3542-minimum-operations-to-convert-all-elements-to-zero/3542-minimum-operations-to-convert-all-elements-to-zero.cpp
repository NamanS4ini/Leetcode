class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (s.size() && nums[i] < s.top())
                s.pop();
            if (nums[i] != 0 && (s.empty() || s.top() != nums[i])){
                count++;
                s.push(nums[i]);
            }
        }
        return count;
    }
};