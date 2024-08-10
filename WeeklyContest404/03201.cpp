#include <vector>
using namespace std;
class Solution {
private:
    int dp(int idx, bool prev_val, bool val, vector<int>& nums, vector<vector<vector<int>>>&mem){
        if(idx == nums.size()) return 0;
        if(mem[idx][prev_val][val] != -1) return mem[idx][prev_val][val];
        mem[idx][prev_val][val] = (prev_val+nums[idx])%2 == val ? dp(idx+1,nums[idx]%2,val,nums,mem) +1 : dp(idx+1,prev_val,val,nums,mem);
        return mem[idx][prev_val][val];
    }
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<vector<int>>> mem(nums.size(), vector<vector<int>>(2, vector<int>(2,-1)));
        int ans = 0;
        for(int i = nums.size()-2; i>=0; i--){
            ans = max(ans,max(dp(i+1,nums[i]%2,0,nums,mem), dp(i+1,nums[i]%2,1,nums,mem))+1);
        }
        return ans;
    }
};