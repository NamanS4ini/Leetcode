class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carPair;
        for(int i = 0; i< speed.size(); i++){
            carPair.push_back({position[i], speed[i]});
        }
        sort(carPair.begin(), carPair.end());
        stack<pair<int, int>> s;
        for(int i = carPair.size() - 1; i >= 0; i--){
            if(s.empty()){
                s.push(carPair[i]);
                continue;
            }
            float topTime = (target - float(s.top().first))/s.top().second;
            float currTime = (target - float(carPair[i].first))/carPair[i].second;
            if(currTime > topTime){
                s.push(carPair[i]);
            }
        }
        return s.size();
    }
};