class Twitter {
    int time = 0;
    unordered_map<int, stack<pair<int, int>>> Id2Post;
    unordered_map<int, unordered_set<int>> Id2Follow;

public:
    void postTweet(int userId, int tweetId) {
        Id2Post[userId].push({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> followList = Id2Follow[userId];
        followList.insert(userId);
        for (int follow : followList) {
            stack<pair<int, int>> s = Id2Post[follow];
            while (!s.empty()) {
                pq.push(s.top());
                s.pop();
            }
        } 
        vector<int> ans;
        int size = pq.size() < 10 ? pq.size() : 10;
        for (int i = 0; i < size; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            Id2Follow[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        Id2Follow[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */