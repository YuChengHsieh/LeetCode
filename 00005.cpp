#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        for(int i=0; i<s.size(); i++) dp[i][i] = true;
        int max_len = 1;
        string ans = s.substr(0,1);
        for(int i=s.size(); i>=0; i--){
            for(int j=i+1; j<s.size(); j++){
                if(s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};