#include <vector>
using namespace std;
class Solution {
public:
    int kInversePairs(int n, int k){
        int MOD = pow(10,9)+7;
        vector<vector<long long>> dp(n,vector<long long>(k+1,0));
        dp[0][0] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                if(j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i][j-1] + dp[i-1][j] - (j >= (i+1) ? dp[i-1][j-(i+1)] - MOD : 0);
                dp[i][j] %= MOD;
            }
        }
        return int(dp[n-1][k]%= MOD);
    }

};