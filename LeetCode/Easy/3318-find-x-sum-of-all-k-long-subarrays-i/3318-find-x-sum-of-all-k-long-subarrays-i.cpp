class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for(int i = 0; i <= nums.size() - k; i++){
            unordered_map<int, int> freq;
            for(int j = i; j < i+k; j++){
                freq[nums[j]]++;
            }
            priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for(auto& p: freq){
                pq.push({p.second, p.first});
                if(pq.size() > x)
                    pq.pop();
            }
            int sum = 0;
            while(pq.size()){
                pair<int,int> p = pq.top();
                pq.pop();
                sum += p.first * p.second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};