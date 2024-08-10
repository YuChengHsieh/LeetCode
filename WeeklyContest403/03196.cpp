#include <vector>
using namespace std;
class Solution {
private:
    long long dp(int idx, bool flip, vector<int>& nums, vector<vector<long long>>& mem){
        if(idx == nums.size()) return 0;
        if(mem[idx][flip] != -1) return mem[idx][flip];
        long long ans = max(dp(idx+1,!flip,nums,mem) + (flip ? -nums[idx] : nums[idx]), dp(idx+1,flip,nums,mem) + nums[idx]);
        return mem[idx][flip] = ans;
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long>> mem(nums.size(), vector<long long>(2,-1));
        return dp(0,false,nums,mem);
    }
};