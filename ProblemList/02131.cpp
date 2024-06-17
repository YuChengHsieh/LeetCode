#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans = 0;

        for(string s: words){
            mp[s] ++;
        }

        bool same = false;
        for(auto& item: mp){
            string rev;
            rev += item.first.back();
            rev += item.first[0];
            if(item.first != rev){if(mp.count(rev)) ans += 2*min(item.second, mp[rev]);}
            else{
                ans += 2*( (item.second%2 == 1) ? item.second-1 : item.second);
                if(item.second%2 == 1) same = true;
            }
            
        }
        return ans + 2*same;
    }
};