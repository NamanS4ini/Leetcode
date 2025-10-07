class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> dis;
        for(vector<int> v: points)
            dis.push_back(sqrt(v[0] * v[0] + v[1] * v[1]));
        
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < dis.size(); i++){
            pq.push({dis[i], i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};