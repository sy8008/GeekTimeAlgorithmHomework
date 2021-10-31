#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

class User{
public:
    User(int _userid, int _tweeid): userId(_userid){postedTweet.push_back({_tweeid,User::time++});};
    User(){};
    User(int _userid): userId(_userid){};
    int userId;
    static int time; // 发送推特的时间，所有对象共享。越新发时间值越大
    vector<pair<int,int>> postedTweet; // 发送的推特 key: 推特id  value: 时间
    // vector<int> followees; // 关注的人
    unordered_set<int> followees; // 关注的人

};

int User:: time = 0;
class Twitter {
public:
    Twitter() {
        
    }
    void postTweet(int userId, int tweetId) {
        // bool findedUser = false;

        // // 查找当前用户是否存在
        // for (auto & user : users){
        //     if (user.userId == userId){
        //         findedUser = true;
        //         user.postedTweet.push_back({tweetId,User::time++}); 
        //     }
        // }

        // // 如果没有当前用户
        // if (!findedUser){
        //     User newUser = User(userId,tweetId);
        // }

        // 查找当前用户是否存在
        if (users.find(userId) != users.end()){
            users[userId].postedTweet.push_back({tweetId,User::time++}); 
        } else{ // 如果当前用户不存在，新建用户
            User newUser = User(userId,tweetId);
            users[userId] = newUser;
        }

    }   
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> allTweets(users[userId].postedTweet);

        for (auto followeeId : users[userId].followees){
            allTweets.insert(allTweets.end(),users[followeeId].postedTweet.begin(),users[followeeId].postedTweet.end()); // 添加关注者发布的twitter
        }
        sort(allTweets.begin(),allTweets.end(),[](const pair<int,int> &p1,const pair<int,int>& p2){return p1.second > p2.second;}); // 按照时间从新到旧排序

        vector<int> ans;
        cout << "User: " << userId << endl;
        int cnt = 0;
        for (auto tweet:allTweets){
            if (cnt < 10){
                ans.push_back(tweet.first);
                cout << tweet.first << " ";
                cnt ++;
            }

        }
        cout << endl;
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        
        // 如果用户不存在，则创建
        if (users.find(followerId) == users.end()){
            users[followerId] = User(followerId);
        }

        if (users.find(followeeId) == users.end()){
            users[followeeId] = User(followeeId);
        }

        // 关注用户
        users[followerId].followees.insert(followeeId);
          
             
         
    }
    
    void unfollow(int followerId, int followeeId) {
        // 取消关注
        users[followerId].followees.erase(followeeId);
    }

    // vector<User> users;
    vector<int> existedUserId; 
    unordered_map<int,User> users;
    





};

int main(){

    Twitter twitter;
    twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
    twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
    twitter.follow(1, 2);    // 用户 1 关注了用户 2
    twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
    twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
    twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
    twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中



    return 0 ;

}