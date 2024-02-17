#include <vector>
using namespace std;

// tabulation
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int cur = 1;
            while (cur * cur <= i) {
                dp[i] = min(dp[i], dp[i - cur * cur] + 1);
                cur++;
            }
        }
        
        return dp[n];
    }
};

// memorization
class Solution {
private:
    int rec(int val, vector<int> & mem){
        // if(val < 0) return INT_MAX;
        if(val == 0) return 0;
        if(mem[val] != INT_MAX) return mem[val];

        int ret = INT_MAX;
        for(int i=1; i*i <= val; i++){
            ret = min(ret,rec(val-i*i,mem)+1);
        }
        mem[val] = ret;
        return mem[val];
    }
public:
    int numSquares(int n) {
        vector<int> mem(n+1,INT_MAX);
        mem[0] = 0;
        return rec(n,mem);
    }
};