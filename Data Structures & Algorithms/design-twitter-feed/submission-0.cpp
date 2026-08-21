class Twitter {
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, vector<pair<int, int>>> arr;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        arr[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto& tweet : arr[userId]){
            pq.push(tweet);
            if(pq.size() > 10) pq.pop();
        }
        for(int followId : mp[userId]){
            for(auto& tweet : arr[followId]){
                pq.push(tweet);
                if(pq.size() > 10) pq.pop();
            }
        }
        vector<int> res(pq.size());
        int i = res.size() - 1;
        while(!pq.empty()){
            res[i] = pq.top().second;
            i--;
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
