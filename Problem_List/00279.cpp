#include <vector>
using namespace std;
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