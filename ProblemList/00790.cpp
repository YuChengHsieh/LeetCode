#include <vector>
using namespace std;

// use traditional dp logic
class Solution {
public:
    int numTilings(int n) {
        int MOD = pow(10,9)+7;
        vector<long> dp(n+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                if(j >= 3)dp[i] += dp[i-j]*2;
                else dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
        return int(dp.back());
    }
};

// observe recurrence relation
class Solution {
public:
    int numTilings(int n) {
        if(n==1 || n==2) return n;
        int MOD = pow(10,9)+7;
        vector<long> dp(n,0);
        dp[0] = 1;
        dp[1] = 2; 
        dp[2] = 5;
        for(int i=3; i<n; i++){
            dp[i] = 2*dp[i-1] + dp[i-3];
            dp[i] %= MOD;
        }
        return int(dp.back());
    }
};