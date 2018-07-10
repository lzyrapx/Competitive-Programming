class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    vector<pair<int,int>>posts;
    map<int,map<int,int>>mp;
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int cnt = 0;
        for(int i = posts.size() - 1; i >= 0 && cnt < 10; --i) {
            if(posts[i].first == userId || mp[userId][posts[i].first] == 1) // 包括userId自己的也能看
            {
                ans.push_back(posts[i].second);
                cnt++;
            }
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        mp[followerId][followeeId] = 1;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        mp[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */