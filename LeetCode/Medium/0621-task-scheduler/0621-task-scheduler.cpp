class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while (pq.size() || q.size()) {
            time++;
            if (pq.size()) {
                int p = pq.top();
                pq.pop();
                if (p - 1 > 0)
                    q.push({time + n, p - 1});
            }
            if (q.size() && q.front().first <= time) {
                pq.push(q.front().second);
                q.pop();
            }
        }

        return time;
    }
};