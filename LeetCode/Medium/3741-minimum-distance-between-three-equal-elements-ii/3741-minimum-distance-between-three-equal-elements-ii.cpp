class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for(int i = 0; i < nums.size(); i++){
            pos[nums[i]].push_back(i);
        }
        int mini = INT_MAX;
        for(auto& t: pos){
            vector<int> tuple = t.second;
            if(tuple.size() < 3){
                continue;
            }
            for(int i = 0; i < tuple.size() - 2; i++){
                int t1 = tuple[i];
                int t2 = tuple[i+1];
                int t3 = tuple[i+2];
                mini = min(mini, abs(t1 - t2) + abs(t2 - t3) + abs(t1 - t3));
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};