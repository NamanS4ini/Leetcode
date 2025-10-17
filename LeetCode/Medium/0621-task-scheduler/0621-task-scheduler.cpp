class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> timeout(26, 0);
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], static_cast<char>(i + 'A')});
        }
        int time = 0;
        while (pq.size()) {
            pair<int, char> p;
            time++;
            vector<pair<int, char>> temp;
            while (pq.size()) {
                p = pq.top();
                if (timeout[p.second - 'A'] == 0) {
                    pq.pop();
                    timeout[p.second - 'A'] = n + 1;
                    if (p.first - 1 > 0)
                        pq.push({p.first - 1, p.second});
                    break;
                }
                else{
                    temp.push_back(p);
                    pq.pop();
                }
            }
            while(temp.size()){
                pq.push(temp[temp.size() - 1]);
                temp.pop_back();
            }
            for (int i = 0; i < 26; i++) {
                if (timeout[i] != 0)
                    timeout[i]--;
            }
        }

        return time;
    }
};