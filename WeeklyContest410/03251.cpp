#include <vector>
using namespace std;

// tabulation o(nums.size()*1000)
class Solution {
public:
    int countOfPairs(vector<int>& nums){
        vector<vector<long long>> dp(nums.size()+1, vector<long long>(1001,0));
        int mod = pow(10,9) + 7;

        for(int i=0; i<=1000; i++){
            dp[nums.size()][i] = 1;
        }

        for(int i=nums.size()-1; i>=0; i--){
            int diff = 0;
            if(i > 0) diff = max(diff, nums[i]-nums[i-1]);
            for(int j=1000; j>=0; j--){
                if(j+1 <= 1000) dp[i][j] = dp[i][j+1];
                if(j+diff <= nums[i]) dp[i][j] += dp[i+1][j+diff];
                dp[i][j] %= mod;
            }
        }
        return (int)dp[0][0];
    }
};