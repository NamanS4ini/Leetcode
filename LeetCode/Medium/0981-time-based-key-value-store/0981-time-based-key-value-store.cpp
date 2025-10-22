class TimeMap {
    // Key, vector<{timestamp, value}>
    unordered_map<string, vector<pair<int, string>>> timeMap;
public:
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& keyMap = timeMap[key];
        int left = 0;
        int right = keyMap.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(keyMap[mid].first == timestamp)
                return keyMap[mid].second;
            if(keyMap[mid].first > timestamp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right == -1 ? "" : keyMap[right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */