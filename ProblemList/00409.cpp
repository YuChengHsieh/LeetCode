#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto& ch: s){
            mp[ch] += 1;
        }

        int ans = 0;
        bool odd = false;
        for(auto& item: mp){
            if(item.second%2 == 1) odd = true;
            ans += item.second - (item.second%2 == 1);
        }
        return ans + odd;
    }
};