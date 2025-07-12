class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int maxFreq = 0;
        for (int num : nums) {
            m[num]++;
            maxFreq = max(maxFreq, m[num]);
        }
        vector<int> ans;
        while(maxFreq > 0) {

            for (auto num : m) {
                if (num.second == maxFreq) {
                    ans.push_back(num.first);
                    if (ans.size() == k) {
                        break;
                    }
                }
            }
            if (ans.size() == k) {
                break;
            }
            maxFreq--;
        }
        return ans;
    }
};