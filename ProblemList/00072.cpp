#include<string>
#include <vector>
using namespace std;

// tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,INT_MAX));

        dp[0][0] = 0;
        for(int i=1; i<=word1.size(); i++){
            dp[i][0] = dp[i-1][0] + 1;
        }

        for(int i=1; i<=word2.size(); i++){
            dp[0][i] = dp[0][i-1] + 1;
        }
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

// memorization
class Solution {
private:
    int inf = 10000000;
    int dp(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& mem){
        if(idx1 == s1.size() && idx2 == s2.size()) return 0;
        else if(idx1 > s1.size() || idx2 > s2.size()) return inf;
        else if(mem[idx1][idx2] != inf) return mem[idx1][idx2];

        int ret = inf;
        if(idx1 < s1.size() && idx2 < s2.size() && s1[idx1] == s2[idx2]) ret = min(ret, dp(idx1+1, idx2+1, s1, s2, mem));
        else{
            // insert
            ret = min(ret, 1+dp(idx1, idx2+1, s1, s2, mem));
            // delete
            ret = min(ret, 1+dp(idx1+1, idx2, s1, s2, mem));
            // replace
            ret = min(ret, 1+dp(idx1+1, idx2+1, s1, s2, mem));
        }
        mem[idx1][idx2] = ret;
        return ret;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size()+1, vector<int>(word2.size()+1,inf));
        return dp(0, 0, word1, word2, mem);
    }
};