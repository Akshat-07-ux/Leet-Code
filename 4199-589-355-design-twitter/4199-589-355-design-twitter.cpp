class Twitter {
private:
    int timestamp; // To track tweet order
    unordered_map<int, unordered_set<int>> followers; // followerId -> set of followees
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [(timestamp, tweetId)]

public:
    Twitter() {
        timestamp = 0;
    }
    
    // User posts a tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    // Retrieve the 10 most recent tweets in the user's news feed
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // Max heap (timestamp, tweetId)

        // Include user's tweets
        for (auto &tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Include tweets from followed users
        for (int followee : followers[userId]) {
            for (auto &tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        // Get the 10 most recent tweets
        vector<int> result;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    // User follows another user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    // User unfollows another user
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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