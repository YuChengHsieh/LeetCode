#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool check(const string& s){
        int sz = s.size();
        for(int i=0; i<sz/2; i++){
            if(s[i] != s[sz-i-1]) return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1,INT_MAX);
        dp[0] = 0;
        for(int i=0; i<s.size(); i++){
            if(check(s.substr(0,i+1))) dp[i+1] = 0;
            else{
                for(int j=0; j<=i; j++){
                    if(check(s.substr(j,i-j+1))){
                        dp[i+1] = min(dp[i+1], dp[j]+1);
                    }
                }
            }
        }
        return dp.back();
    }
};

// recursion
class Solution {
private:
    int inf = 1000000;
    vector<vector<int>> mem_pa;
    bool check(int start, int end, string& s){
        if(mem_pa[start][end] != -1) return mem_pa[start][end];
        for(int i=0; i<(end-start+1)/2; i++){
            if(s[start+i] != s[end-i]) return mem_pa[start][end] = 0;
        }
        return mem_pa[start][end] = 1;
    }

    int dp(int idx, string& s, vector<int>& mem){
        if(idx == s.size()) return 0;
        if(mem[idx] != -1) return mem[idx];
        int ans = inf;
        
        for(int i=idx; i<s.size(); i++){
            bool fit = check(idx,i,s);
            if(fit) ans = min(ans, dp(i+1,s,mem)+1);
        }
        return mem[idx] = ans;
    }
public:
    int minCut(string s) {
        vector<int> mem(s.size(),-1);
        mem_pa = vector<vector<int>>(s.size(), vector<int>(s.size(),-1));
        return dp(0,s,mem)-1;
    }
};

// like 00005
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        vector<int> dp2(s.size(),0);
        
        for(int i=s.size()-1; i>=0; i--){
            int min_cut = s.size()-i-1;
            for(int j=i; j<s.size(); j++){
                if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    min_cut = j == s.size()-1 ? 0 : min(min_cut, dp2[j+1]+1);
                }
            }
            dp2[i] = min_cut;
        }
        return dp2[0];
    }
};