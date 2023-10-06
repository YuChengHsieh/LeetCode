#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        
        function<int(int, int)> rec = [&](int val, int i) {
            if (i == nums.size()) {
                return int(val == target);
            }
            
            string key = to_string(val) + "-" + to_string(i);
            if (dp.find(key) != dp.end()) {
                return dp[key];
            }
            
            int pos = rec(val + nums[i], i + 1);
            int neg = rec(val - nums[i], i + 1);
            
            dp[key] = pos + neg;
            return dp[key];
        };
        
        return rec(0, 0);
    }
};
