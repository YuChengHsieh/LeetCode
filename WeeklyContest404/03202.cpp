#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1;
        vector<vector<int>> dp(nums.size(), vector<int>(k,1));

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][(nums[i]+nums[j])%k] = max(dp[i][(nums[i]+nums[j])%k], dp[j][(nums[i]+nums[j])%k] + 1);
                max_len = max(max_len, dp[i][(nums[i]+nums[j])%k]);
            }
        }

        return max_len;
    }
};