class Twitter {
    struct Tweet {
        int id;
        int time;

        bool operator<(const Tweet& other) const {
            return time < other.time;
        }
    };

    int timestamp = 0;
    unordered_map<int, priority_queue<Tweet>> tweets;
    // follower, followee
    unordered_map<int, unordered_set<int>> followings;

public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push({tweetId, timestamp++});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> feed(tweets[userId]);
        for (const int f : followings[userId]) {
            priority_queue<Tweet> copy(tweets[f]);
            while (!copy.empty()) {
                feed.push(copy.top());
                copy.pop();
            }
        }

        vector<int> res;
        int i = 0;
        while (!feed.empty() && i < 10) {
            res.push_back(feed.top().id);
            feed.pop();
            ++i;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followings[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
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
