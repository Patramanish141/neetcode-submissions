class Twitter {
public:
    int timestamp;
    vector<pair<int, int>> tweets[501];//array per User used to store timstamp and tweetId
    vector<vector<bool>> follows;

    Twitter() {
        timestamp = 0;
        follows.assign(501, vector<bool>(501, false));
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;//<timestamp, tweetId>
        for(auto &t : tweets[userId]){
            pq.push(t);//push all the pair(timestamp, tweetId) of user to pq
        }

        for(int followeeId=0; followeeId<501; followeeId++){
            if(follows[userId][followeeId]){
                for(auto &t : tweets[followeeId]) pq.push(t);//push the pair(timestamp, tweetId) of persons whom user Follows
            }
        }

        vector<int> result;
        while(!pq.empty() && result.size()<10){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
       follows[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
       follows[followerId][followeeId] = false;
    }
};

