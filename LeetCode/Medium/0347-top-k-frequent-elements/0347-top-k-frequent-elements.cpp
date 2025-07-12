class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        vector<vector<int>> freq(nums.size()+1,vector<int>(0,0));
        for(auto num: m){
            freq[num.second].push_back(num.first);
        }
        vector<int> ans;
        for(int i = freq.size() - 1; i >= 0; i--){
                while(k != 0 && freq[i].size() != 0){
                    ans.push_back(freq[i].back());
                    freq[i].pop_back();
                    k--;
                
            }
        }
        return ans;
    }
};