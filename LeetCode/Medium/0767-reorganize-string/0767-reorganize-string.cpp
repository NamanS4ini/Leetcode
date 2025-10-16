class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char c: s){
            freq[c - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                pq.push({freq[i], static_cast<char>(i + 97)});
        }
        string ans = "";
        while(pq.size()){
            pair<int, char> t1 = pq.top();
            pq.pop();
            if(pq.empty()){
                if(t1.first > 1)
                    return "";
                ans.push_back(t1.second);
                return ans;
            }
            pair<int, char> t2 = pq.top();
            pq.pop();
            ans.push_back(t1.second); 
            if(t1.first > 1)
                pq.push({t1.first - 1, t1.second});
            ans.push_back(t2.second);
            if(t2.first > 1)
                pq.push({t2.first - 1, t2.second});
        }
        return ans;
    }
};