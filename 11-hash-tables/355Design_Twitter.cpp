#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>

class Twitter {
    private:
        struct Tweet{
            int tweetid{0};
            int timepost{0};
        };
        int globalT{0};
        std::unordered_map<int, std::vector<Tweet>> posts{};
        std::unordered_map<int, std::unordered_set<int>> followers{};
    public:
        Twitter() = default;
        
        void postTweet(int userId, int tweetId) {
            globalT++;
            posts[userId].push_back({tweetId, globalT});
        }
        
        std::vector<int> getNewsFeed(int userId) {
            std::vector<int> r{};
            std::priority_queue<std::pair<int,int>> pq{};
            for(const auto &a : posts[userId]){
                pq.push({a.timepost, a.tweetid});
            }
            for(const auto &f : followers[userId]){
                for(const auto &a : posts[f]){
                    pq.push({a.timepost, a.tweetid});
                }
            }
            while(!pq.empty() && r.size() < 10){
                r.push_back(pq.top().second);
                pq.pop();
            }
            return r;
        }
        
        void follow(int followerId, int followeeId) {
            if (followerId == followeeId) return;
            followers[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            if(followers.find(followerId) != followers.end()){
                followers[followerId].erase(followeeId);
            }
        }
};

int main(){
    char stop{};
    std::cout<<"Мини-Твиттер\n";
    do{
        Twitter user;
        user.postTweet(1,5);
        user.getNewsFeed(1);
        user.follow(1,2);
        user.postTweet(2,6);
        user.getNewsFeed(2);
        user.unfollow(1,2);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop == 'y' || stop == 'Y');
    return 0;
}