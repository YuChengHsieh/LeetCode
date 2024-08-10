#include <vector>
using namespace std;
class Solution {
const int MOD = 1e9 + 7;
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        sort(requirements.begin(),requirements.end());
        int idx = 0;
        if(requirements[idx][0] == 0){
            if(requirements[idx][1] != 0) return 0;
            idx ++;
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(401, 0));
        dp[0][0] = 1;
        bool counter = false;
        for(int i=1; i<n; i++){
            long long prefix_sum = 0;
            for(int j=0; j<=min(i*(i+1)/2,400); j++){
                prefix_sum = (prefix_sum+dp[i-1][j])%MOD;
                if(j-i > 0) prefix_sum = (MOD+prefix_sum-dp[i-1][j-i-1])%MOD;
                dp[i][j] = (requirements[idx][0] == i && requirements[idx][1] != j) ? 0 : prefix_sum;
            }
            if(idx < requirements.size() && requirements[idx][0] == i) idx ++;
            
        }
        return dp[n-1][requirements[idx-1][1]]%MOD;
    }
};