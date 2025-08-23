class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> speedPos; 
        for(int i = 0; i < position.size(); i++){
            speedPos.push_back({position[i], speed[i]});
        }
        sort(speedPos.begin(), speedPos.end());
        stack<float> s;
        for(int i = speedPos.size() - 1; i >= 0; i--){
            auto p = speedPos[i];
            float time = (target - float(p.first))/ p.second;
            if(s.empty() || s.top() < time){
                s.push(time);
            }
        }
        return s.size();
    }
};