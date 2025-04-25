#include <vector>
using namespace std;
class Solution {
    private:
        bool dp(int idx, int target, vector<int>& nums, vector<vector<int>>& mem){
            if(target == 0) return true;
            if(idx == nums.size() || target < 0) return false;
            if(mem[idx][target] != -1) return mem[idx][target];
            return mem[idx][target] = dp(idx+1,target-nums[idx],nums,mem) || dp(idx+1,target,nums,mem);
        }
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for(auto&num : nums) sum += num;
            if(sum%2) return false;
            sum /= 2;
            vector<vector<int>> mem(nums.size(),vector<int>(sum+1,-1));
            return dp(0,sum,nums,mem);
        }
    };