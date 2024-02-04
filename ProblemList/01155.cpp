#include <vector>
using namespace std;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target+1,vector<int>(n+1,0));
        
        dp[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int l=1; l<=k; l++){
                for(int j=l; j<=target; j++){
                    dp[j][i] += dp[j-l][i-1];
                    dp[j][i] %= (int(pow(10,9))+7);
                }
            }
        }
        return dp[target][n];
    }
};