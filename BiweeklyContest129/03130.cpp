#include <vector>
using namespace std;
class Solution {
public:
    int mod = pow(10,9)+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<long long>> zeros(zero+1, vector<long long>(one+1,0));
        vector<vector<long long>> ones(zero+1, vector<long long>(one+1,0));
        vector<vector<vector<long long>>> dp(zero+1, vector<vector<long long>>(one+1, vector<long long>(2,0)));
        
        for(int i=0; i<=zero; i++){
            dp[i][0][0] = i<=limit ? 1 : 0;
            zeros[i][0] = dp[i][0][0];
        }

        for(int i=0; i<=one; i++){
            dp[0][i][1] = i<=limit ? 1 : 0;
            ones[0][i] = dp[0][i][1];
        }


        for(int i=1; i<=zero; i++){
            for(int j=1; j<=one; j++){

                dp[i][j][1] = zeros[i][j-1];
                dp[i][j][0] = ones[i-1][j];

                if(i-limit-1 >= 0) dp[i][j][0] = (dp[i][j][0] - ones[i-limit-1][j] + mod)%mod;
                if(j-limit-1 >= 0) dp[i][j][1] = (dp[i][j][1] - zeros[i][j-limit-1] + mod)%mod;

                zeros[i][j] = (zeros[i][j-1] + dp[i][j][0]) % mod;
                ones[i][j] = (ones[i-1][j] + dp[i][j][1]) % mod;
                

            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};
