#include <vector>
#include <map>
using namespace std;

// pick or not pick, knapsack problem
class Solution {
private:
    int inf = 1000000;
    int mask = (1 << 20) - 1;
    int rec(int num_idx, int addVal_idx, int val, vector<int>& nums, vector<int>& andValues, vector<vector<map<int,int>>>& mem){
        if(addVal_idx == andValues.size()) return num_idx == nums.size() ? 0 : inf;
        if(num_idx == nums.size()) return inf;
        if(mem[num_idx][addVal_idx].count(val)) return mem[num_idx][addVal_idx][val];
        int ans = inf;
        if( (val&nums[num_idx]) == andValues[addVal_idx]) ans = min(ans,
            rec(num_idx+1,addVal_idx+1,mask,nums,andValues,mem)+nums[num_idx]);
        ans = min(ans, rec(num_idx+1,addVal_idx,val&nums[num_idx],nums,andValues,mem));
        return mem[num_idx][addVal_idx][val] = ans;
    }
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector<vector<map<int,int>>> mem(nums.size(), vector<map<int,int>>(andValues.size()));
        return rec(0,0,mask,nums,andValues,mem) == inf ? -1 : rec(0,0,mask,nums,andValues,mem);
    }
};