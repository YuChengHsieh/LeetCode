#include <vector>
using namespace std;
class Solution {
    private:
        int inf = 1e5;
        int dp(int idx, int target, int num_idx, vector<vector<int>>& queries, vector<vector<int>>& mem){
            if(target == 0) return idx;
            if(idx == queries.size() || target < 0) return inf;
            if(mem[idx][target] != -1) return mem[idx][target];
            int ans = dp(idx+1,target,num_idx,queries,mem);
            if(num_idx >= queries[idx][0] && num_idx <= queries[idx][1]) ans = min(ans, dp(idx+1,target - queries[idx][2],num_idx,queries,mem));
            return mem[idx][target] = ans;
        }
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int ans = 0;
            for(int i=0; i<nums.size(); i++){
                vector<vector<int>> mem(queries.size(),vector<int>(nums[i]+1,-1));
                ans = max(ans, dp(0,nums[i],i,queries, mem));
                if(ans == inf) return -1;
            }
            return ans;
        }
    };