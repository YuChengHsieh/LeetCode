#include <string>
#include <map>
#include <queue>s
using namespace std;

// heap
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char,int>>> pq;
        for(int i=0; i<s.size(); i++){
            if(s[i] != '*') pq.push({s[i],-i});
            else pq.pop();
        }

        map<int, char> mp; 
        while(!pq.empty()){
            auto i = pq.top();
            mp[-i.second] = i.first;
            pq.pop();
        }

        string ans;
        for(auto i: mp){
            ans += i.second;
        }
        return ans;
    }
};

// map
class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> pos(26);
        map<int,char> mp;
        for(int i=0; i<s.size(); i++){
            if(s[i] != '*'){
                pos[s[i]-'a'].push_back(i);
                mp[i] = s[i];
            } 
            else{
                for(int i=0; i<26; i++){
                    if(pos[i].size() != 0){
                        mp.erase(pos[i].back());
                        pos[i].pop_back();
                        break;
                    }
                }
            }
        }

        string ans;
        for(auto& item: mp){
            ans += item.second;
        }
        return ans;
    }
};